/*
 * Copyright 2012-2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		John Scipione, jscipione@gmail.com
 */


#include "Hexagon.h"

#include <Message.h>
#include <Point.h>
#include <PickerProtocol.h>
#include <Rect.h>
#include <Shape.h>


Hexagon::Hexagon()
	:
	BControl(BRect(0, 0, kHexagonWidth - 1, kHexagonHeight - 1), "Hexagon",
		"", new BMessage(B_VALUE_CHANGED), B_FOLLOW_NONE, B_WILL_DRAW),
	fColor((rgb_color) { 255, 0, 0 }),
	fIsSelected(false),
	fMouseDownMessage(NULL)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}


Hexagon::Hexagon(rgb_color color)
	:
	BControl(BRect(0, 0, kHexagonWidth - 1, kHexagonHeight - 1), "Hexagon",
		"", new BMessage(B_VALUE_CHANGED), B_FOLLOW_NONE, B_WILL_DRAW),
	fColor(color),
	fIsSelected(false),
	fMouseDownMessage(NULL)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}


Hexagon::~Hexagon()
{
}


void
Hexagon::AttachedToWindow()
{
}


void
Hexagon::Draw(BRect updateRect)
{
	PushState();
	SetHighColor(fColor);
	SetLowColor(Parent()->ViewColor());
	BShape* hexagon = new BShape();
	hexagon->MoveTo(BPoint(kHexagonWidth / 2.0f, 0.0f));
	hexagon->LineTo(BPoint(kHexagonWidth,
		floorf(kHexagonHeight / 3.0f - 1.0f)));
	hexagon->LineTo(BPoint(kHexagonWidth,
		ceilf(kHexagonHeight * 2.0f / 3.0f + 1.0f)));
	hexagon->LineTo(BPoint(kHexagonWidth / 2.0f, kHexagonHeight));
	hexagon->LineTo(BPoint(0.0f,
		ceilf(kHexagonHeight * 2.0f / 3.0f + 1.0f)));
	hexagon->LineTo(BPoint(0.0f, floorf(kHexagonHeight / 3.0f - 1.0f)));
	hexagon->LineTo(BPoint(kHexagonWidth / 2.0f, 0.0f));
	hexagon->Close();
	FillShape(hexagon);

	if (fIsSelected) {
		SetHighColor((rgb_color) { 127, 127, 127 });
		SetLowColor((rgb_color) { 255, 255, 255 });
		StrokeShape(hexagon);

		// outer border (white)
		BShape* outer = new BShape();
		outer->MoveTo(BPoint(kHexagonWidth / 2.0f, 1.0f));
		outer->LineTo(BPoint(kHexagonWidth - 1.0f,
			ceilf(kHexagonHeight / 3.0f - 1.0f)));
		outer->LineTo(BPoint(kHexagonWidth - 1.0f,
			floorf(kHexagonHeight * 2.0f / 3.0f + 1.0f)));
		outer->LineTo(BPoint(kHexagonWidth / 2.0f, kHexagonHeight - 1.0f));
		outer->LineTo(BPoint(1.0f, floorf(kHexagonHeight * 2.0f / 3.0f + 1.0f)));
		outer->LineTo(BPoint(1.0f, ceilf(kHexagonHeight / 3.0f - 1.0f)));
		outer->LineTo(BPoint(kHexagonWidth / 2.0f, 1.0f));
		outer->Close();
		SetPenSize(2.0);
		StrokeShape(outer);
		delete outer;

		// inner border (white)
		BShape* inner = new BShape();
		inner->MoveTo(BPoint(kHexagonWidth / 2.0f, 2.0f));
		inner->LineTo(BPoint(kHexagonWidth - 2.0f,
			ceilf(kHexagonHeight / 3.0f - 1.0f)));
		inner->LineTo(BPoint(kHexagonWidth - 2.0f,
			floorf(kHexagonHeight * 2.0f / 3.0f + 1.0f)));
		inner->LineTo(BPoint(kHexagonWidth / 2.0f, kHexagonHeight - 2.0f));
		inner->LineTo(BPoint(2.0f, floorf(kHexagonHeight * 2.0f / 3.0f + 1.0f)));
		inner->LineTo(BPoint(2.0f, ceilf(kHexagonHeight / 3.0f - 1.0f)));
		inner->LineTo(BPoint(kHexagonWidth / 2.0f, 2.0f));
		inner->Close();
		SetPenSize(1.0);
		StrokeShape(inner, B_SOLID_LOW);
		delete inner;
	}

	PopState();
	delete hexagon;
}


status_t
Hexagon::Invoke(BMessage* message)
{
	if (message == NULL)
		message = Message();

	message->AddData("RGBColor", B_RGB_COLOR_TYPE, &fColor, sizeof(fColor));

	return BControl::Invoke(message);
}


void
Hexagon::MouseDown(BPoint where)
{
	fMouseDownMessage = new BMessage(B_VALUE_CHANGED);
	Invoke(fMouseDownMessage);

	BControl::MouseDown(where);
}


void
Hexagon::MouseUp(BPoint where)
{
	delete fMouseDownMessage;
	fMouseDownMessage = NULL;

	BControl::MouseUp(where);
}


rgb_color
Hexagon::Color() const
{
	return fColor;
}


void
Hexagon::SetColor(rgb_color color)
{
	color.alpha = 255;
	fColor = color;
	if (Window() != NULL)
		Invalidate(Bounds());
}


bool
Hexagon::Selected() const
{
	return fIsSelected;
}


void
Hexagon::SetSelected(bool isSelected)
{
	fIsSelected = isSelected;
		Invalidate();
}
