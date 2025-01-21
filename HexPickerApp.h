/*
 * Copyright 2012-2021 2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef HEX_PICKER_APP_H
#define HEX_PICKER_APP_H


#include <Application.h>
#include <ColorPickerPanel.h>


extern const char* kSignature;


using BPrivate::BColorPickerPanel;


class HexPicker;

class HexPickerPanel : public BColorPickerPanel {
public:
					HexPickerPanel(HexPicker* view, BMessage* message);
	virtual			~HexPickerPanel();
};

class HexPickerApp : public BApplication {
public:
								HexPickerApp();
	virtual						~HexPickerApp();

	virtual	void				MessageReceived(BMessage* message);
	virtual	void				ReadyToRun();

private:
			HexPickerPanel*		fPanel;
};


#endif	// HEX_PICKER_APP_H
