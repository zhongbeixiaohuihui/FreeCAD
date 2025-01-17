/***************************************************************************
 *   Copyright (c) 2015 Balázs Bámer                                       *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#ifndef SURFACEGUI_TASKGEOMLINKWIRE_H
#define SURFACEGUI_TASKGEOMLINKWIRE_H

#include <Gui/TaskView/TaskDialog.h>
#include <Gui/TaskView/TaskView.h>
#include <Gui/SelectionFilter.h>
#include <Gui/DocumentObserver.h>
#include <Base/BoundBox.h>
#include <Mod/Part/Gui/ViewProviderSpline.h>
#include <Mod/Surface/App/FeatureGeomFillSurface.h>
#include <Mod/Surface/App/FeatureGeomLinkWire.h>
#include <GeomFill_FillingStyle.hxx>

class QListWidgetItem;

namespace SurfaceGui
{

class Ui_GeomFillSurface;

//class ViewProviderGeomFillSurface : public PartGui::ViewProviderSpline
//{
//    PROPERTY_HEADER(SurfaceGui::ViewProviderGeomFillSurface);
//public:
//    virtual void setupContextMenu(QMenu*, QObject*, const char*);
//    virtual bool setEdit(int ModNum);
//    virtual void unsetEdit(int ModNum);
//    QIcon getIcon(void) const;
//    void highlightReferences(bool on);
//};

class GeomLinkWire : public QWidget,
                        public Gui::SelectionObserver,
                        public Gui::DocumentObserver
{
    Q_OBJECT

protected:
    class EdgeSelection;
    enum SelectionMode { None, Append, Remove };
    SelectionMode selectionMode;
    Surface::GeomLinkWire* editedObject;
    bool checkCommand;

private:
    Ui_GeomLinkWire* ui;
    ViewProviderGeomLinkWire* vp;

public:
    GeomLinkWire(ViewProviderGeomLinkWire* vp, Surface::GeomLinkWire* obj);
    ~GeomLinkWire();

    void open();
    void checkOpenCommand();
    bool accept();
    bool reject();
    void setEditedObject(Surface::GeomLinkWire* obj);

protected:
    void changeEvent(QEvent *e);
    virtual void onSelectionChanged(const Gui::SelectionChanges& msg);
    /** Notifies on undo */
    virtual void slotUndoDocument(const Gui::Document& Doc);
    /** Notifies on redo */
    virtual void slotRedoDocument(const Gui::Document& Doc);
    /** Notifies when the object is about to be removed. */
    virtual void slotDeletedObject(const Gui::ViewProviderDocumentObject& Obj);
    void changeFillType(GeomFill_FillingStyle);
    void flipOrientation(QListWidgetItem*);

private Q_SLOTS:
    void on_fillType_stretch_clicked();
    void on_fillType_coons_clicked();
    void on_fillType_curved_clicked();
    void on_buttonEdgeAdd_clicked();
    void on_buttonEdgeRemove_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem*);
    void onDeleteEdge(void);
    void onFlipOrientation();
    void clearSelection();
};

class TaskGeomLinkWire : public Gui::TaskView::TaskDialog
{
    Q_OBJECT

public:
    TaskGeomLinkWire(ViewProviderGeomLinkWire* vp, Surface::GeomLinkWire* obj);
    ~TaskGeomLinkWire();
    void setEditedObject(Surface::GeomLinkWire* obj);

public:
    void open();
    bool accept();
    bool reject();

    virtual QDialogButtonBox::StandardButtons getStandardButtons() const
    { return QDialogButtonBox::Ok | QDialogButtonBox::Cancel; }

private:
    GeomLinkWire* widget;
    Gui::TaskView::TaskBox* taskbox;
};

} //namespace SurfaceGui

#endif // SURFACEGUI_TaskGeomLinkWire_H
