/////////////////////////////////////////////////////////////////////////////
// Name:          ceWxSerial.h
// Description:   Serial module for wxWidgets
// Author:        Yan Naing Aye
/////////////////////////////////////////////////////////////////////////////

#ifndef CEWXSERIAL_H
#include "wx/wx.h"
#include <vector>
#include "ce/ceserial.h"
namespace ce {

class ceWxSerial : public wxEvtHandler, public ceSerial {
public:
	ceWxSerial(wxEvtHandler* app,int id, int interval, 
		std::string Device, long BaudRate, long DataSize, char ParityType, float NStopBits);
	~ceWxSerial();
	void OnTimer(wxTimerEvent& event);
	std::vector<char> Chk();
private:
	wxTimer* _timer;
	wxEvtHandler* _app;
	int _id;
	int _interval;
};

} // namespace ce 
#endif // CEWXSERIAL_H
