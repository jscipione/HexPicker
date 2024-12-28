/*
 * Copyright 2012-2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef HEXAGON_H
#define HEXAGON_H


#include <Control.h>


const int32 kHexagonWidth = 19;
const int32 kHexagonHeight = 22;


class BMessage;
class BPoint;
class BRect;

class Hexagon : public BControl {
public:
								Hexagon();
								Hexagon(rgb_color color);
	virtual						~Hexagon();

	virtual	void				AttachedToWindow();
	virtual	void				Draw(BRect updateRect);
	virtual status_t			Invoke(BMessage* message = NULL);
	virtual	void				MouseDown(BPoint where);
	virtual	void				MouseUp(BPoint where);

			rgb_color			Color() const;
			void				SetColor(rgb_color color);

			bool				Selected() const;
			void				SetSelected(bool isSelected);

protected:
			rgb_color			fColor;
			bool				fIsSelected;

private:
			BMessage*			fMouseDownMessage;
};


#endif	// HEXAGON_H
