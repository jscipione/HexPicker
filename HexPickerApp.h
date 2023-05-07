/*
 * Copyright 2012-2021 2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef HEX_PICKER_APP_H
#define HEX_PICKER_APP_H


#include <Application.h>


extern const char* kSignature;


class HexPickerPanel;

class HexPickerApp : public BApplication {
public:
								HexPickerApp();
	virtual						~HexPickerApp();

	virtual	void				MessageReceived(BMessage* message);
	virtual	void				ReadyToRun();

private:
			HexPickerPanel*		fPanel;
			rgb_color			fDefaultColor;
};


#endif	// HEX_PICKER_APP_H
