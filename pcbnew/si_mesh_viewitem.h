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
 * @file si_mesh_viewitem.h
 * @brief Class that draws the triangle mesh used for SI simulation.
 */

#ifndef SI_MESH_VIEWITEM_H
#define SI_MESH_VIEWITEM_H

#include <base_struct.h>

namespace KIGFX
{
class SI_MESH_VIEWITEM : public EDA_ITEM
{
public:
    SI_MESH_VIEWITEM( );

    /// @copydoc VIEW_ITEM::ViewBBox()
    const BOX2I ViewBBox() const override;

    /// @copydoc VIEW_ITEM::ViewDraw()
    void ViewDraw( int aLayer, KIGFX::VIEW* aView ) const override;

    /// @copydoc VIEW_ITEM::ViewGetLayers()
    void ViewGetLayers( int aLayers[], int& aCount ) const override;

#if defined(DEBUG)
    /// @copydoc EDA_ITEM::Show()
    void Show( int x, std::ostream& st ) const override
    {
    }
#endif

    /** Get class name
     * @return  string "SI_MESH_VIEWITEM"
     */
    virtual wxString GetClass() const override
    {
        return wxT( "SI_MESH_VIEWITEM" );
    }
};

}   // namespace KIGFX

#endif /* SI_MESH_VIEWITEM_H */
