#ifndef PHASE3_SENDCHARGINGINFORMATIONARG
#define PHASE3_SENDCHARGINGINFORMATIONARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_SendChargingInformationArg
{
	SendChargingInformationArg_SCIBILLINGCHARGINGCHARACTERISTICS	=  1 << 0,
	SendChargingInformationArg_PARTYTOCHARGE	=  1 << 1,
	SendChargingInformationArg_EXTENSIONS	=  1 << 2,
	SendChargingInformationArg_TAG_NULL	=  0x0000
}SendChargingInformationArg_tags;

		//! Class Definition
		/*!		ClassName is SendChargingInformationArg
		*/
class SendChargingInformationArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CAMEL_SCIBillingChargingCharacteristics*		msCIBillingChargingCharacteristics;

		SendingSideID*		mpartyToCharge;

		Extensions*		mextensions;


	public:
		SendChargingInformationArg();

		~SendChargingInformationArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument sCIBillingChargingCharacteristics for datatype SendChargingInformationArg
		*/
		bool setsCIBillingChargingCharacteristics(CAMEL_SCIBillingChargingCharacteristics* sCIBillingChargingCharacteristics);

		//! Function to set values
		/*!		Function to set OctetString type of argument sCIBillingChargingCharacteristics for datatype SendChargingInformationArg
		*/
		CAMEL_SCIBillingChargingCharacteristics* setsCIBillingChargingCharacteristics();

		//! Function to get values
		/*!		Function to set OctetString type of argument sCIBillingChargingCharacteristics for datatype SendChargingInformationArg
		Throws exception of which type and Summary of Exception
		*/
		CAMEL_SCIBillingChargingCharacteristics* getsCIBillingChargingCharacteristics() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype SendChargingInformationArg
		*/
		bool setpartyToCharge(SendingSideID* partyToCharge);

		//! Function to set values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype SendChargingInformationArg
		*/
		SendingSideID* setpartyToCharge();

		//! Function to get values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype SendChargingInformationArg
		Throws exception of which type and Summary of Exception
		*/
		SendingSideID* getpartyToCharge() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype SendChargingInformationArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype SendChargingInformationArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype SendChargingInformationArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype SendChargingInformationArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype SendChargingInformationArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SendChargingInformationArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags SendChargingInformationArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
