//  @(#) $Id: RequestReportSMSEventArg.h,v 1.1.2.3 2019/06/29 02:24:30 mrafi Exp $";

#ifndef REQUESTREPORTSMSEVENTARG
#define REQUESTREPORTSMSEVENTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_RequestReportSMSEventArg
{
	RequestReportSMSEventArg_SMSEVENTS	=  1 << 0,
	RequestReportSMSEventArg_EXTENSIONS	=  1 << 1,
	RequestReportSMSEventArg_TAG_NULL	=  0x0000
}RequestReportSMSEventArg_tags;

		//! Class Definition
		/*!		ClassName is RequestReportSMSEventArg
		*/
class RequestReportSMSEventArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		unsigned mCounter;

		unsigned mMinNoOfSMSEvent;

		unsigned mMaxNoOfSMSEvent;

		bool CheckSMSEventBoundary();

		vector<SMSEvent *> msMSEventsList;

		SMSEvent*  msMSEvents;

		int DecodeSeqOfSMSEvent(capstd::capstd::byteArray* array, unsigned *bytesParsed);

		Extensions*		mextensions;


	public:
		RequestReportSMSEventArg();

		~RequestReportSMSEventArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set SMSEvent type of argument sMSEvents for datatype RequestReportSMSEventArg
		*/
		bool setsMSEvents(SMSEvent* sMSEvents);

		//!Function to set values
		/*!		Function to set the recent SMSEvent type of argument sMSEvents for datatype RequestReportSMSEventArg
		*/
		SMSEvent* setsMSEvents();

		//!Function to set values
		/*!		Function to Create new SMSEvent type of argument sMSEvents for datatype RequestReportSMSEventArg
		*/
		SMSEvent* setNewsMSEvents();

		//!Function to get values
		/*!		Function to get first SMSEvent type of argument sMSEvents for datatype RequestReportSMSEventArg
		Throws exception of which type and Summary of Exception
		*/
		SMSEvent* getsMSEvents() ; //;//throw(const char*)

		//!Function to get number values
		/*!		Function to get number of SMSEvent type of argument sMSEvents for datatype RequestReportSMSEventArg
		*/
		unsigned getNoOfsMSEvents();

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype RequestReportSMSEventArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype RequestReportSMSEventArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype RequestReportSMSEventArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype RequestReportSMSEventArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype RequestReportSMSEventArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RequestReportSMSEventArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags RequestReportSMSEventArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
