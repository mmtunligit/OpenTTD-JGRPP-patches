/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file waybill_gui.cpp GUIs related to waybills. */

#include "stdafx.h"
#include "waybill_gui.h"
#include "window_type.h"
#include "window_gui.h"
#include "company_base.h"

#include "widgets/waybill_widget.h"

#include "table/strings.h"
#include "table/sprites.h"

class WaybillListWindow : public Window
{
protected:

public:
	WaybillListWindow(WindowDesc &desc, WindowNumber window_number) : Window(desc)
	{
		this->CreateNestedTree();
		this->FinishInitNested(window_number);
	}

	void OnClick([[maybe_unused]] Point pt, WidgetID widget, [[maybe_unused]] int click_count) override
	{
		switch (widget) {
			case WID_WBL_ADD_WAYBILL: {

			}
		}
	}
};

static constexpr NWidgetPart _nested_waybill_list_widgets[] = {
	NWidget(NWID_HORIZONTAL),
		NWidget(WWT_CLOSEBOX, COLOUR_GREY),
		NWidget(WWT_CAPTION, COLOUR_GREY, WID_WBL_CAPTION),
		NWidget(WWT_SHADEBOX, COLOUR_GREY),
		NWidget(WWT_DEFSIZEBOX, COLOUR_GREY),
		NWidget(WWT_STICKYBOX, COLOUR_GREY),
	EndContainer(),
	NWidget(NWID_HORIZONTAL),
		NWidget(WWT_TEXTBTN, COLOUR_GREY, WID_WBL_TRAIN), SetAspect(WidgetDimensions::ASPECT_VEHICLE_ICON), SetStringTip(STR_TRAIN, STR_STATION_LIST_USE_CTRL_TO_SELECT_MORE_TOOLTIP), SetFill(0, 1),
		NWidget(WWT_TEXTBTN, COLOUR_GREY, WID_WBL_TRUCK), SetAspect(WidgetDimensions::ASPECT_VEHICLE_ICON), SetStringTip(STR_LORRY, STR_STATION_LIST_USE_CTRL_TO_SELECT_MORE_TOOLTIP), SetFill(0, 1),
		NWidget(WWT_TEXTBTN, COLOUR_GREY, WID_WBL_BUS), SetAspect(WidgetDimensions::ASPECT_VEHICLE_ICON), SetStringTip(STR_BUS, STR_STATION_LIST_USE_CTRL_TO_SELECT_MORE_TOOLTIP), SetFill(0, 1),
		NWidget(WWT_TEXTBTN, COLOUR_GREY, WID_WBL_SHIP), SetAspect(WidgetDimensions::ASPECT_VEHICLE_ICON), SetStringTip(STR_SHIP, STR_STATION_LIST_USE_CTRL_TO_SELECT_MORE_TOOLTIP), SetFill(0, 1),
		NWidget(WWT_TEXTBTN, COLOUR_GREY, WID_WBL_AIRPLANE), SetAspect(WidgetDimensions::ASPECT_VEHICLE_ICON), SetStringTip(STR_PLANE, STR_STATION_LIST_USE_CTRL_TO_SELECT_MORE_TOOLTIP), SetFill(0, 1),
		NWidget(WWT_PUSHTXTBTN, COLOUR_GREY, WID_WBL_FACILALL), SetAspect(WidgetDimensions::ASPECT_VEHICLE_ICON), SetStringTip(STR_ABBREV_ALL, STR_WAYBILL_LIST_SELECT_ALL_MODES), SetTextStyle(TC_BLACK, FS_SMALL), SetFill(0, 1),
		NWidget(WWT_PANEL, COLOUR_GREY), SetMinimalSize(5, 0), SetFill(0, 1), EndContainer(),
		NWidget(WWT_DROPDOWN, COLOUR_GREY, WID_WBL_CARGODROPDOWN), SetFill(1, 0), SetToolTip(STR_STATION_LIST_USE_CTRL_TO_SELECT_MORE_TOOLTIP),
		NWidget(WWT_DROPDOWN, COLOUR_GREY, WID_WBL_COMPANYDROPDOWN), SetFill(1, 0), SetToolTip(STR_STATION_LIST_USE_CTRL_TO_SELECT_MORE_TOOLTIP),
		NWidget(WWT_PANEL, COLOUR_GREY), SetResize(1, 0), SetFill(1, 1), EndContainer(),
	EndContainer(),
	NWidget(NWID_HORIZONTAL),
		NWidget(WWT_PUSHTXTBTN, COLOUR_GREY, WID_WBL_SORTBY), SetMinimalSize(81, 12), SetStringTip(STR_BUTTON_SORT_BY, STR_TOOLTIP_SORT_ORDER),
		NWidget(WWT_DROPDOWN, COLOUR_GREY, WID_WBL_SORTDROPBTN), SetMinimalSize(163, 12), SetStringTip(STR_SORT_BY_NAME, STR_TOOLTIP_SORT_CRITERIA), // widget_data gets overwritten. TODO change string
		NWidget(WWT_PANEL, COLOUR_GREY), SetResize(1, 0), SetFill(1, 1), EndContainer(),
	EndContainer(),
	NWidget(NWID_HORIZONTAL),
	NWidget(WWT_PANEL, COLOUR_GREY, WID_WBL_LIST), SetMinimalSize(346, 125), SetResize(1, 10), SetToolTip(STR_STATION_LIST_TOOLTIP), SetScrollbar(WID_WBL_SCROLLBAR), EndContainer(),
	NWidget(NWID_VSCROLLBAR, COLOUR_GREY, WID_WBL_SCROLLBAR),
	EndContainer(),
	NWidget(NWID_HORIZONTAL, NWidContainerFlag::EqualSize),
		NWidget(WWT_PUSHTXTBTN, COLOUR_GREY, WID_WBL_ADD_WAYBILL), SetMinimalSize(46, 12), SetResize(1, 0), SetFill(1, 1),
	SetStringTip(STR_WAYBILL_LIST_ADD_WAYBILL_BUTTON, STR_WAYBILL_LIST_ADD_WAYBILL_TOOLTIP),
		NWidget(WWT_PUSHTXTBTN, COLOUR_GREY, WID_WBL_EDIT_WAYBILL), SetMinimalSize(60, 12), SetResize(1, 0), SetFill(1, 1),
	SetStringTip(STR_WAYBILL_LIST_EDIT_WAYBILL_BUTTON, STR_WAYBILL_LIST_EDIT_WAYBILL_TOOLTIP),
		NWidget(WWT_PUSHTXTBTN, COLOUR_GREY, WID_WBL_SET_START_DATE), SetMinimalSize(60, 12), SetResize(1, 0), SetFill(1, 1),
	SetStringTip(STR_WAYBILL_LIST_SET_START_DATE_BUTTON, STR_WAYBILL_LIST_SET_START_DATE_TOOLTIP),
		NWidget(WWT_PUSHIMGBTN, COLOUR_GREY, WID_WBL_DEACTIVATE), SetSpriteTip(SPR_FLAG_VEH_STOPPED), SetAspect(WidgetDimensions::ASPECT_VEHICLE_FLAG), SetFill(0, 1), //TODO strings
		NWidget(WWT_PUSHIMGBTN, COLOUR_GREY, WID_WBL_ACTIVATE), SetSpriteTip(SPR_FLAG_VEH_RUNNING), SetAspect(WidgetDimensions::ASPECT_VEHICLE_FLAG), SetFill(0, 1), //TODO strings
		NWidget(WWT_PUSHIMGBTN, COLOUR_GREY, WID_WBL_ASSIGNED_VEH), SetAspect(1), SetSpriteTip(SPR_SHARED_ORDERS_ICON, STR_WAYBILL_LIST_SHOW_ASSIGNED_VEH_TOOLTIP),
	NWidget(WWT_RESIZEBOX, COLOUR_GREY),
	EndContainer(),
};

static WindowDesc _waybill_list_desc(__FILE__, __LINE__,
	WDP_AUTO, "toolbar_landscape", 358, 162,
		WC_WAYBILL_LIST, WC_NONE,
	{},
	_nested_waybill_list_widgets
);

/**
 * Opens window with list of company's waybills
 * TODO comments
 * @param company whose stations' list show
 */
void ShowWaybillList(/*CompanyID company*/)
{
	//if (!Company::IsValidID(company)) return;

	AllocateWindowDescFront<WaybillListWindow>(_waybill_list_desc, 0/*company*/);
}
