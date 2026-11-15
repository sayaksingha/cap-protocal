#ifndef PHASE3_APPLYCHARGINGARG
#define PHASE3_APPLYCHARGINGARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ApplyChargingArg
{
	ApplyChargingArg_ACHBILLINGCHARGINGCHARACTERISTICS	=  1 << 0,
	ApplyChargingArg_PARTYTOCHARGE	=  1 << 1,
	ApplyChargingArg_EXTENSIONS	=  1 << 2,
	ApplyChargingArg_TAG_NULL	=  0x0000
}ApplyChargingArg_tags;

		//! Class Definition
		/*!		ClassName is ApplyChargingArg
		*/
class ApplyChargingArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CAMEL_AChBillingChargingCharacteristics*		maChBillingChargingCharacteristics;

		SendingSideID* partyToChargeDefault;
		SendingSideID*		mpartyToCharge;

		Extensions*		mextensions;


	public:
		ApplyChargingArg();

		~ApplyChargingArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument aChBillingChargingCharacteristics for datatype ApplyChargingArg
		*/
		bool setaChBillingChargingCharacteristics(CAMEL_AChBillingChargingCharacteristics* aChBillingChargingCharacteristics);

		//! Function to set values
		/*!		Function to set OctetString type of argument aChBillingChargingCharacteristics for datatype ApplyChargingArg
		*/
		CAMEL_AChBillingChargingCharacteristics* setaChBillingChargingCharacteristics();

		//! Function to get values
		/*!		Function to set OctetString type of argument aChBillingChargingCharacteristics for datatype ApplyChargingArg
		Throws exception of which type and Summary of Exception
		*/
		CAMEL_AChBillingChargingCharacteristics* getaChBillingChargingCharacteristics() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype ApplyChargingArg
		*/
		bool setpartyToCharge(SendingSideID* partyToCharge);

		//! Function to set values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype ApplyChargingArg
		*/
		SendingSideID* setpartyToCharge();

		//! Function to get values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype ApplyChargingArg
		Throws exception of which type and Summary of Exception
		*/
		SendingSideID* getpartyToCharge() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ApplyChargingArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ApplyChargingArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype ApplyChargingArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ApplyChargingArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ApplyChargingArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ApplyChargingArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ApplyChargingArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
