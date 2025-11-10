/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file viewport_widget.h Types related to the waybill widgets. */

#ifndef WIDGETS_WAYBILL_WIDGET_H
#define WIDGETS_WAYBILL_WIDGET_H

/** Widgets of the #WaybillListWindow class. */
enum WaybillListWidgets : WidgetID {
	WID_WBL_CAPTION,        ///< Caption of window.
	WID_WBL_LIST,           ///< The main panel, list of stations.
	WID_WBL_SCROLLBAR,      ///< Scrollbar next to the main panel.
	WID_WBL_ADD_WAYBILL,    ///< Add waybill button.
	WID_WBL_EDIT_WAYBILL,   ///< Edit waybill button.
	WID_WBL_SET_START_DATE, ///< Set start date button.
	WID_WBL_DEACTIVATE,     ///< Deactivate some waybills.
	WID_WBL_ACTIVATE,       ///< Activate some waybills.
	WID_WBL_ASSIGNED_VEH,   ///< View vehicles assigned to waybills.


	/* Vehicletypes need to be in order of StationFacility(?) due to bit magic */
	WID_WBL_TRAIN,          ///< 'TRAIN' button - list only rail waybills.
	WID_WBL_TRUCK,          ///< 'TRUCK' button - list only truck waybills.
	WID_WBL_BUS,            ///< 'BUS' button - list only bus waybills.
	WID_WBL_AIRPLANE,       ///< 'AIRPLANE' button - list only airplane waybills.
	WID_WBL_SHIP,           ///< 'SHIP' button - list only ship waybills.
	WID_WBL_FACILALL,       ///< 'ALL' button - list all vehicle types.

	WID_WBL_SORTBY,         ///< 'Sort by' button - reverse sort direction.
	WID_WBL_SORTDROPBTN,    ///< Dropdown button.

	WID_WBL_CARGODROPDOWN,  ///< Cargo type dropdown list.
	WID_WBL_COMPANYDROPDOWN,///< Company dropdown list.
};

#endif /* WIDGETS_VIEWPORT_WIDGET_H */
