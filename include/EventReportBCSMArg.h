#ifndef PHASE3_EVENTREPORTBCSMARG
#define PHASE3_EVENTREPORTBCSMARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_EventReportBCSMArg
{
	EventReportBCSMArg_EVENTTYPEBCSM	=  1 << 0,
	EventReportBCSMArg_EVENTSPECIFICINFORMATIONBCSM	=  1 << 1,
	EventReportBCSMArg_LEGID	=  1 << 2,
	EventReportBCSMArg_MISCCALLINFO	=  1 << 3,
	EventReportBCSMArg_EXTENSIONS	=  1 << 4,
	EventReportBCSMArg_TAG_NULL	=  0x0000
}EventReportBCSMArg_tags;

		//! Class Definition
		/*!		ClassName is EventReportBCSMArg
		*/
class EventReportBCSMArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		EventTypeBCSM*		meventTypeBCSM;

		EventSpecificInformationBCSM*		meventSpecificInformationBCSM;

		ReceivingSideID*		mlegID;

		MiscCallInfo*		mmiscCallInfo;

		Extensions*		mextensions;


	public:
		EventReportBCSMArg();

		~EventReportBCSMArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype EventReportBCSMArg
		*/
		bool seteventTypeBCSM(EventTypeBCSM* eventTypeBCSM);

		//! Function to set values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype EventReportBCSMArg
		*/
		EventTypeBCSM* seteventTypeBCSM();

		//! Function to get values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype EventReportBCSMArg
		Throws exception of which type and Summary of Exception
		*/
		EventTypeBCSM* geteventTypeBCSM() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set EventSpecificInformationBCSM type of argument eventSpecificInformationBCSM for datatype EventReportBCSMArg
		*/
		bool seteventSpecificInformationBCSM(EventSpecificInformationBCSM* eventSpecificInformationBCSM);

		//! Function to set values
		/*!		Function to set EventSpecificInformationBCSM type of argument eventSpecificInformationBCSM for datatype EventReportBCSMArg
		*/
		EventSpecificInformationBCSM* seteventSpecificInformationBCSM();

		//! Function to get values
		/*!		Function to set EventSpecificInformationBCSM type of argument eventSpecificInformationBCSM for datatype EventReportBCSMArg
		Throws exception of which type and Summary of Exception
		*/
		EventSpecificInformationBCSM* geteventSpecificInformationBCSM() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ReceivingSideID type of argument legID for datatype EventReportBCSMArg
		*/
		bool setlegID(ReceivingSideID* legID);

		//! Function to set values
		/*!		Function to set ReceivingSideID type of argument legID for datatype EventReportBCSMArg
		*/
		ReceivingSideID* setlegID();

		//! Function to get values
		/*!		Function to set ReceivingSideID type of argument legID for datatype EventReportBCSMArg
		Throws exception of which type and Summary of Exception
		*/
		ReceivingSideID* getlegID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set MiscCallInfo type of argument miscCallInfo for datatype EventReportBCSMArg
		*/
		bool setmiscCallInfo(MiscCallInfo* miscCallInfo);

		//! Function to set values
		/*!		Function to set MiscCallInfo type of argument miscCallInfo for datatype EventReportBCSMArg
		*/
		MiscCallInfo* setmiscCallInfo();

		//! Function to get values
		/*!		Function to set MiscCallInfo type of argument miscCallInfo for datatype EventReportBCSMArg
		Throws exception of which type and Summary of Exception
		*/
		MiscCallInfo* getmiscCallInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype EventReportBCSMArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype EventReportBCSMArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype EventReportBCSMArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype EventReportBCSMArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype EventReportBCSMArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype EventReportBCSMArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags EventReportBCSMArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
