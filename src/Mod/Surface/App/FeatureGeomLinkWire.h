/***************************************************************************
 *   Copyright (c) 2014-2015 Nathan Miller    <Nathan.A.Mill[at]gmail.com> *
 *                           Balázs Bámer                                  *
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

#ifndef FEATUREGEOMLINKWIRE_H
#define FEATUREGEOMLINKWIRE_H

#include <Geom_BoundedSurface.hxx>
#include <GeomFill_FillingStyle.hxx>
#include <ShapeExtend_WireData.hxx>

#include <App/PropertyStandard.h>
#include <App/PropertyUnits.h>
#include <App/PropertyLinks.h>
#include <Mod/Part/App/FeaturePartSpline.h>

namespace Surface
{

class GeomLinkWire : public Part::Spline
{
  PROPERTY_HEADER(Surface::GeomFillSurface);

public:
	GeomLinkWire();
    App::PropertyLinkSubList BoundaryList;  // Curves to be turned into a face (2-4 curves allowed).
	App::PropertyLinkSubList ShapeList;     //Shapes cut tool.
    
    short mustExecute() const;
    void onChanged(const App::Property*);
    App::DocumentObjectExecReturn *execute(void);
private:

};

}

#endif // FEATUREGEOMLINKWIRE_H
