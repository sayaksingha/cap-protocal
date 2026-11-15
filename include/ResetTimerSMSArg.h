//  @(#) $Id: ResetTimerSMSArg.h,v 1.1.2.3 2019/06/29 02:24:30 mrafi Exp $";

#ifndef RESETTIMERSMSARG
#define RESETTIMERSMSARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ResetTimerSMSArg
{
	ResetTimerSMSArg_TIMERID	=  1 << 0,
	ResetTimerSMSArg_TIMERVALUE	=  1 << 1,
	ResetTimerSMSArg_EXTENSIONS	=  1 << 2,
	ResetTimerSMSArg_TAG_NULL	=  0x0000
}ResetTimerSMSArg_tags;

		//! Class Definition
		/*!		ClassName is ResetTimerSMSArg
		*/
class ResetTimerSMSArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		TimerID* timerIDDefault;
		TimerID*		mtimerID;

		capstd::capstd::INTEGER*		mtimervalue;

		Extensions*		mextensions;


	public:
		ResetTimerSMSArg();

		~ResetTimerSMSArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set TimerID type of argument timerID for datatype ResetTimerSMSArg
		*/
		bool settimerID(TimerID* timerID);

		//! Function to set values
		/*!		Function to set TimerID type of argument timerID for datatype ResetTimerSMSArg
		*/
		TimerID* settimerID();

		//! Function to get values
		/*!		Function to set TimerID type of argument timerID for datatype ResetTimerSMSArg
		Throws exception of which type and Summary of Exception
		*/
		TimerID* gettimerID() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument timervalue for datatype ResetTimerSMSArg
		*/
		bool settimervalue(capstd::capstd::INTEGER* timervalue);

		//! Function to set values
		/*!		Function to set INTEGER type of argument timervalue for datatype ResetTimerSMSArg
		*/
		capstd::capstd::INTEGER* settimervalue();

		//! Function to get values
		/*!		Function to set INTEGER type of argument timervalue for datatype ResetTimerSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::INTEGER* gettimervalue() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ResetTimerSMSArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ResetTimerSMSArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype ResetTimerSMSArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ResetTimerSMSArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ResetTimerSMSArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ResetTimerSMSArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ResetTimerSMSArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
