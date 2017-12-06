/*
 * This program source code file is part of KICAD, a free EDA CAD application.
 *
 * Copyright (C) 2017 Andreas Buhr
 * @author Andreas Buhr <andreas@andreasbuhr.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/**
 * @file si_mesh_viewitem.cpp
 * @brief Class that draws the triangle mesh used for SI simulation.
 */

#include <si_mesh_viewitem.h>
#include <gal/graphics_abstraction_layer.h>
#include <layers_id_colors_and_visibility.h>
#include <pcb_painter.h>

#include <memory>

#include <view/view.h>

namespace KIGFX {

SI_MESH_VIEWITEM::SI_MESH_VIEWITEM( ) :
        EDA_ITEM( NOT_USED )
{
}


const BOX2I SI_MESH_VIEWITEM::ViewBBox() const
{
    // Make it always visible
    BOX2I bbox;
    bbox.SetMaximum();

    return bbox;
}

void SI_MESH_VIEWITEM::ViewDraw( int aLayer, KIGFX::VIEW* aView ) const
{
    // just draw a cross, to test
    constexpr int CROSS_SIZE = 500000;

    auto gal = aView->GetGAL();
	gal->SetIsStroke( true );
    gal->SetIsFill( false );
    gal->SetLineWidth( 1.0 );
    auto rs = aView->GetPainter()->GetSettings();
    auto color = rs->GetColor( NULL, LAYER_RATSNEST );


    gal->SetStrokeColor( color.Brightened(0.8) );

    gal->DrawLine( VECTOR2I( 0 - CROSS_SIZE, 0 - CROSS_SIZE ), VECTOR2I( 0 + CROSS_SIZE, 0 + CROSS_SIZE ) );
    gal->DrawLine( VECTOR2I( 0 - CROSS_SIZE, 0 + CROSS_SIZE ), VECTOR2I( 0 + CROSS_SIZE, 0 - CROSS_SIZE ) );
}


void SI_MESH_VIEWITEM::ViewGetLayers( int aLayers[], int& aCount ) const
{
    aCount = 1;
    aLayers[0] = LAYER_SI_MESH;
}

}
