/*
 * Copyright 2012-2025 John Scipione. All rights reserved.
 *
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
								HexPicker();
	virtual						~HexPicker();

	virtual	void				AttachedToWindow();
	virtual	void				MessageReceived(BMessage* message);
	virtual	void				MouseDown(BPoint where);
	virtual	void				MouseMoved(BPoint where, uint32 code,
									const BMessage* dragMessage);
	virtual	void				MouseUp(BPoint where);

			rgb_color			Color() const { return fColor; };
			void				SetColor(rgb_color color);

private:
			rgb_color			fColor;
			BTextControl*		fHexTextControl;
			int32				fHexagonCount;
			Hexagon*			fHexagonList[kMaxHexagonCount];
			BPoint				fMouseOffset;
			bool				fMouseDown : 1;
};


#endif	// HEX_PICKER_H
