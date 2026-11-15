#ifndef PHASE3_ESTABLISHTEMPORARYCONNECTIONARG
#define PHASE3_ESTABLISHTEMPORARYCONNECTIONARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_EstablishTemporaryConnectionArg
{
	EstablishTemporaryConnectionArg_ASSISTINGSSPIPROUTINGADDRESS	=  1 << 0,
	EstablishTemporaryConnectionArg_CORRELATIONID	=  1 << 1,
	EstablishTemporaryConnectionArg_SCFID	=  1 << 2,
	EstablishTemporaryConnectionArg_EXTENSIONS	=  1 << 3,
	EstablishTemporaryConnectionArg_CARRIER	=  1 << 4,
	EstablishTemporaryConnectionArg_SERVICEINTERACTIONINDICATORSTWO	=  1 << 5,
	EstablishTemporaryConnectionArg_NAOLIINFO	=  1 << 6,
	EstablishTemporaryConnectionArg_CHARGENUMBER	=  1 << 7,
	EstablishTemporaryConnectionArg_TAG_NULL	=  0x0000
}EstablishTemporaryConnectionArg_tags;

		//! Class Definition
		/*!		ClassName is EstablishTemporaryConnectionArg
		*/
class EstablishTemporaryConnectionArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		massistingSSPIPRoutingAddress;

		capstd::OctetString*		mcorrelationID;

		capstd::OctetString*		mscfID;

		Extensions*		mextensions;

		capstd::OctetString*		mcarrier;

		ServiceInteractionIndicatorsTwo*		mserviceInteractionIndicatorsTwo;

		capstd::OctetString*		mnaOliInfo;

		capstd::OctetString*		mchargeNumber;


	public:
		EstablishTemporaryConnectionArg();

		~EstablishTemporaryConnectionArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument assistingSSPIPRoutingAddress for datatype EstablishTemporaryConnectionArg
		*/
		bool setassistingSSPIPRoutingAddress(capstd::OctetString* assistingSSPIPRoutingAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument assistingSSPIPRoutingAddress for datatype EstablishTemporaryConnectionArg
		*/
		capstd::OctetString* setassistingSSPIPRoutingAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument assistingSSPIPRoutingAddress for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getassistingSSPIPRoutingAddress() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument correlationID for datatype EstablishTemporaryConnectionArg
		*/
		bool setcorrelationID(capstd::OctetString* correlationID);

		//! Function to set values
		/*!		Function to set OctetString type of argument correlationID for datatype EstablishTemporaryConnectionArg
		*/
		capstd::OctetString* setcorrelationID();

		//! Function to get values
		/*!		Function to set OctetString type of argument correlationID for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcorrelationID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument scfID for datatype EstablishTemporaryConnectionArg
		*/
		bool setscfID(capstd::OctetString* scfID);

		//! Function to set values
		/*!		Function to set OctetString type of argument scfID for datatype EstablishTemporaryConnectionArg
		*/
		capstd::OctetString* setscfID();

		//! Function to get values
		/*!		Function to set OctetString type of argument scfID for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getscfID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype EstablishTemporaryConnectionArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype EstablishTemporaryConnectionArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype EstablishTemporaryConnectionArg
		*/
		bool setcarrier(capstd::OctetString* carrier);

		//! Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype EstablishTemporaryConnectionArg
		*/
		capstd::OctetString* setcarrier();

		//! Function to get values
		/*!		Function to set OctetString type of argument carrier for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcarrier() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype EstablishTemporaryConnectionArg
		*/
		bool setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo);

		//! Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype EstablishTemporaryConnectionArg
		*/
		ServiceInteractionIndicatorsTwo* setserviceInteractionIndicatorsTwo();

		//! Function to get values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		ServiceInteractionIndicatorsTwo* getserviceInteractionIndicatorsTwo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument naOliInfo for datatype EstablishTemporaryConnectionArg
		*/
		bool setnaOliInfo(capstd::OctetString* naOliInfo);

		//! Function to set values
		/*!		Function to set OctetString type of argument naOliInfo for datatype EstablishTemporaryConnectionArg
		*/
		capstd::OctetString* setnaOliInfo();

		//! Function to get values
		/*!		Function to set OctetString type of argument naOliInfo for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getnaOliInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument chargeNumber for datatype EstablishTemporaryConnectionArg
		*/
		bool setchargeNumber(capstd::OctetString* chargeNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument chargeNumber for datatype EstablishTemporaryConnectionArg
		*/
		capstd::OctetString* setchargeNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument chargeNumber for datatype EstablishTemporaryConnectionArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getchargeNumber() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype EstablishTemporaryConnectionArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype EstablishTemporaryConnectionArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype EstablishTemporaryConnectionArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags EstablishTemporaryConnectionArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
