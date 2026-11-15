#ifndef PHASE3_APPLYCHARGINGREPORTARG
#define PHASE3_APPLYCHARGINGREPORTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ApplyChargingReportArg
{
	ApplyChargingReportArg_CALLREULT	=  1 << 0,
	ApplyChargingReportArg_TIMEDURATION	=  1 << 1,
	ApplyChargingReportArg_TAG_NULL	=  0x0000
}ApplyChargingReportArg_tags;

		//! Class Definition
		/*!		ClassName is ApplyChargingReportArg
		*/
class ApplyChargingReportArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CAMEL_CallResult*		mcallReult;

		TimeDurationChargingResult*		mtimeduration;


	public:
		ApplyChargingReportArg();

		~ApplyChargingReportArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CAMEL_CallResult type of argument callReult for datatype ApplyChargingReportArg
		*/
		bool setcallReult(CAMEL_CallResult* callReult);

		//! Function to set values
		/*!		Function to set CAMEL_CallResult type of argument callReult for datatype ApplyChargingReportArg
		*/
		CAMEL_CallResult* setcallReult();

		//! Function to get values
		/*!		Function to set CAMEL_CallResult type of argument callReult for datatype ApplyChargingReportArg
		Throws exception of which type and Summary of Exception
		*/
		CAMEL_CallResult* getcallReult() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TimeDurationChargingResult type of argument timeduration for datatype ApplyChargingReportArg
		*/
		bool settimeduration(TimeDurationChargingResult* timeduration);

		//! Function to set values
		/*!		Function to set TimeDurationChargingResult type of argument timeduration for datatype ApplyChargingReportArg
		*/
		TimeDurationChargingResult* settimeduration();

		//! Function to get values
		/*!		Function to set TimeDurationChargingResult type of argument timeduration for datatype ApplyChargingReportArg
		Throws exception of which type and Summary of Exception
		*/
		TimeDurationChargingResult* gettimeduration() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ApplyChargingReportArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ApplyChargingReportArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ApplyChargingReportArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ApplyChargingReportArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
