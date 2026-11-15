#ifndef PHASE3_CONTINUEWITHARGUMENTARG
#define PHASE3_CONTINUEWITHARGUMENTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ContinueWithArgumentArg
{
	ContinueWithArgumentArg_ALERTINGPATTERN	=  1 << 0,
	ContinueWithArgumentArg_EXTENSIONS	=  1 << 1,
	ContinueWithArgumentArg_SERVICEINTERACTIONINDICATORSTWO	=  1 << 2,
	ContinueWithArgumentArg_CALLINGPARTYSCATEGORY	=  1 << 3,
	ContinueWithArgumentArg_GENERICNUMBERS	=  1 << 4,
	ContinueWithArgumentArg_CUG_INTERLOCK	=  1 << 5,
	ContinueWithArgumentArg_CUG_OUTGOINGACCESS	=  1 << 6,
	ContinueWithArgumentArg_CHARGENUMBER	=  1 << 7,
	ContinueWithArgumentArg_CARRIER	=  1 << 8,
	ContinueWithArgumentArg_SUPPRESSIONOFANNOUNCEMENT	=  1 << 9,
	ContinueWithArgumentArg_NAOLIINFO	=  1 << 10,
	ContinueWithArgumentArg_TAG_NULL	=  0x0000
}ContinueWithArgumentArg_tags;

		//! Class Definition
		/*!		ClassName is ContinueWithArgumentArg
		*/
class ContinueWithArgumentArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		malertingPattern;

		Extensions*		mextensions;

		ServiceInteractionIndicatorsTwo*		mserviceInteractionIndicatorsTwo;

		capstd::OctetString*		mcallingPartysCategory;

		GenericNumbers*		mgenericNumbers;

		capstd::OctetString*		mcug_Interlock;

		bool 		mcug_OutgoingAccess;

		bool 		mNullcug_OutgoingAccess;

		capstd::OctetString*		mchargeNumber;

		capstd::OctetString*		mcarrier;

		bool 		msuppressionOfAnnouncement;

		bool 		mNullsuppressionOfAnnouncement;

		capstd::OctetString*		mnaOliInfo;


	public:
		ContinueWithArgumentArg();

		~ContinueWithArgumentArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument alertingPattern for datatype ContinueWithArgumentArg
		*/
		bool setalertingPattern(capstd::OctetString* alertingPattern);

		//! Function to set values
		/*!		Function to set OctetString type of argument alertingPattern for datatype ContinueWithArgumentArg
		*/
		capstd::OctetString* setalertingPattern();

		//! Function to get values
		/*!		Function to set OctetString type of argument alertingPattern for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getalertingPattern() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ContinueWithArgumentArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ContinueWithArgumentArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ContinueWithArgumentArg
		*/
		bool setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo);

		//! Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ContinueWithArgumentArg
		*/
		ServiceInteractionIndicatorsTwo* setserviceInteractionIndicatorsTwo();

		//! Function to get values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		ServiceInteractionIndicatorsTwo* getserviceInteractionIndicatorsTwo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype ContinueWithArgumentArg
		*/
		bool setcallingPartysCategory(capstd::OctetString* callingPartysCategory);

		//! Function to set values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype ContinueWithArgumentArg
		*/
		capstd::OctetString* setcallingPartysCategory();

		//! Function to get values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallingPartysCategory() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GenericNumbers type of argument genericNumbers for datatype ContinueWithArgumentArg
		*/
		bool setgenericNumbers(GenericNumbers* genericNumbers);

		//! Function to set values
		/*!		Function to set GenericNumbers type of argument genericNumbers for datatype ContinueWithArgumentArg
		*/
		GenericNumbers* setgenericNumbers();

		//! Function to get values
		/*!		Function to set GenericNumbers type of argument genericNumbers for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		GenericNumbers* getgenericNumbers() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype ContinueWithArgumentArg
		*/
		bool setcug_Interlock(capstd::OctetString* cug_Interlock);

		//! Function to set values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype ContinueWithArgumentArg
		*/
		capstd::OctetString* setcug_Interlock();

		//! Function to get values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcug_Interlock() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument cug_OutgoingAccess for datatype ContinueWithArgumentArg
		*/
		bool setcug_OutgoingAccess(bool cug_OutgoingAccess);

		//! Function to set new values
		/*!		Function to set NULL type of argument cug_OutgoingAccess for datatype ContinueWithArgumentArg
		*/
		bool* setcug_OutgoingAccess();

		//! Function to get values
		/*!		Function to get NULL type of argument cug_OutgoingAccess for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		bool getcug_OutgoingAccess();

		//!Function to set values
		/*!		Function to set OctetString type of argument chargeNumber for datatype ContinueWithArgumentArg
		*/
		bool setchargeNumber(capstd::OctetString* chargeNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument chargeNumber for datatype ContinueWithArgumentArg
		*/
		capstd::OctetString* setchargeNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument chargeNumber for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getchargeNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype ContinueWithArgumentArg
		*/
		bool setcarrier(capstd::OctetString* carrier);

		//! Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype ContinueWithArgumentArg
		*/
		capstd::OctetString* setcarrier();

		//! Function to get values
		/*!		Function to set OctetString type of argument carrier for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcarrier() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument suppressionOfAnnouncement for datatype ContinueWithArgumentArg
		*/
		bool setsuppressionOfAnnouncement(bool suppressionOfAnnouncement);

		//! Function to set new values
		/*!		Function to set NULL type of argument suppressionOfAnnouncement for datatype ContinueWithArgumentArg
		*/
		bool* setsuppressionOfAnnouncement();

		//! Function to get values
		/*!		Function to get NULL type of argument suppressionOfAnnouncement for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		bool getsuppressionOfAnnouncement();

		//!Function to set values
		/*!		Function to set OctetString type of argument naOliInfo for datatype ContinueWithArgumentArg
		*/
		bool setnaOliInfo(capstd::OctetString* naOliInfo);

		//! Function to set values
		/*!		Function to set OctetString type of argument naOliInfo for datatype ContinueWithArgumentArg
		*/
		capstd::OctetString* setnaOliInfo();

		//! Function to get values
		/*!		Function to set OctetString type of argument naOliInfo for datatype ContinueWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getnaOliInfo() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ContinueWithArgumentArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ContinueWithArgumentArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ContinueWithArgumentArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ContinueWithArgumentArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
