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

#include "PreCompiled.h"

#ifndef _PreComp_
#include <BRep_Tool.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepBuilderAPI_Copy.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GeomFill.hxx>
#include <GeomFill_BezierCurves.hxx>
#include <GeomFill_BSplineCurves.hxx>
#include <gp_Trsf.hxx>
#include <ShapeConstruct_Curve.hxx>
#include <ShapeFix_Wire.hxx>
#include <ShapeExtend_WireData.hxx>
#include <Standard_ConstructionError.hxx>
#include <StdFail_NotDone.hxx>
#include <TopExp_Explorer.hxx>
#endif

#include <Base/Exception.h>
#include <Base/Tools.h>

#include "FeatureGeomLinkWire.h"
#include "FeatureGeomFillSurface.h"

using namespace Surface;

PROPERTY_SOURCE(Surface::GeomLinkWire, Part::Spline)

GeomLinkWire::GeomLinkWire(): Spline()
{
 
    ADD_PROPERTY(BoundaryList, (0, "Dummy"));
	ADD_PROPERTY(ShapeList, (0, "Dummy"));
    BoundaryList.setScope(App::LinkScope::Global);
	ShapeList.setScope(App::LinkScope::Global);
}


//Check if any components of the surface have been modified
short GeomLinkWire::mustExecute() const
{
    if (BoundaryList.isTouched()) {
        return 1;
    }
	if (ShapeList.isTouched()) {
		return 1;
	}
    return Spline::mustExecute();
}

void GeomLinkWire::onChanged(const App::Property* prop)
{
    if (isRestoring()) {
        if (prop == &BoundaryList) {
            
        }
    }
    Part::Spline::onChanged(prop);
}

App::DocumentObjectExecReturn *GeomLinkWire::execute(void)
{
    //try {
    //    TopoDS_Wire aWire;

    //    //Gets the healed wire
    //    if (getWire(aWire)) {
    //        createBezierSurface(aWire);
    //    }
    //    else {
    //        createBSplineSurface(aWire);
    //    }

    //    return App::DocumentObject::StdReturn;
    //}
    //catch (Standard_ConstructionError&) {
    //    // message is in a Latin language, show a normal one
    //    return new App::DocumentObjectExecReturn("Curves are disjoint.");
    //}
    //catch (StdFail_NotDone&) {
    //    return new App::DocumentObjectExecReturn("A curve was not a B-spline and could not be converted into one.");
    //}
    //catch (Standard_Failure& e) {
    //    return new App::DocumentObjectExecReturn(e.GetMessageString());
    //}
}
