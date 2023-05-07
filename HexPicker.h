/*
 * Copyright 2012-20132023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef HEX_PICKER_H
#define HEX_PICKER_H


#include <View.h>


const int32 kMaxHexagonCount = 143;


class BMessage;
class BPoint;
class BTextControl;
class Hexagon;


class HexPicker : public BView {
public:
								HexPicker(rgb_color color);
	virtual						~HexPicker();

	virtual	void				AttachedToWindow();
	virtual	void				MessageReceived(BMessage* message);

			rgb_color			Color() const { return fColor; };
			void				SetColor(rgb_color color);

private:
			rgb_color			fColor;
			Hexagon*			fHexagonList[kMaxHexagonCount];
			int32				fHexagonCount;
			BTextControl*		fHexTextControl;
};


#endif	// HEX_PICKER_H
