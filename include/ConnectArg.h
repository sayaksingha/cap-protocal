#ifndef PHASE3_CONNECTARG
#define PHASE3_CONNECTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ConnectArg
{
	ConnectArg_DESTINATIONROUTINGADDRESS	=  1 << 0,
	ConnectArg_ALERTINGPATTERN	=  1 << 1,
	ConnectArg_ORIGINALCALLEDPARTYID	=  1 << 2,
	ConnectArg_EXTENSIONS	=  1 << 3,
	ConnectArg_CARRIER	=  1 << 4,
	ConnectArg_CALLINGPARTYSCATEGORY	=  1 << 5,
	ConnectArg_REDIRECTINGPARTYID	=  1 << 6,
	ConnectArg_REDIRECTIONINFORMATION	=  1 << 7,
	ConnectArg_GENERICNUMBERS	=  1 << 8,
	ConnectArg_SERVICEINTERACTIONINDICATORSTWO	=  1 << 9,
	ConnectArg_CHARGENUMBER	=  1 << 10,
	ConnectArg_CUG_INTERLOCK	=  1 << 11,
	ConnectArg_CUG_OUTGOINGACCESS	=  1 << 12,
	ConnectArg_SUPPRESSIONOFANNOUNCEMENT	=  1 << 13,
	ConnectArg_OCSIAPPLICABLE	=  1 << 14,
	ConnectArg_NAOLIINFO	=  1 << 15,
	ConnectArg_TAG_NULL	=  0x0000
}ConnectArg_tags;

		//! Class Definition
		/*!		ClassName is ConnectArg
		*/
class ConnectArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		DestinationRoutingAddress*		mdestinationRoutingAddress;

		capstd::OctetString*		malertingPattern;

		capstd::OctetString*		moriginalCalledPartyID;

		Extensions*		mextensions;

		capstd::OctetString*		mcarrier;

		capstd::OctetString*		mcallingPartysCategory;

		capstd::OctetString*		mredirectingPartyID;

		capstd::GENERIC*		mredirectionInformation;

		GenericNumbers*		mgenericNumbers;

		ServiceInteractionIndicatorsTwo*		mserviceInteractionIndicatorsTwo;

		capstd::OctetString*		mchargeNumber;

		capstd::OctetString*		mcug_Interlock;

		bool 		mcug_OutgoingAccess;

		bool 		mNullcug_OutgoingAccess;

		bool 		msuppressionOfAnnouncement;

		bool 		mNullsuppressionOfAnnouncement;

		bool 		moCSIApplicable;

		bool 		mNulloCSIApplicable;

		capstd::OctetString*		mnaOliInfo;


	public:
		ConnectArg();

		~ConnectArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set DestinationRoutingAddress type of argument destinationRoutingAddress for datatype ConnectArg
		*/
		bool setdestinationRoutingAddress(DestinationRoutingAddress* destinationRoutingAddress);

		//! Function to set values
		/*!		Function to set DestinationRoutingAddress type of argument destinationRoutingAddress for datatype ConnectArg
		*/
		DestinationRoutingAddress* setdestinationRoutingAddress();

		//! Function to get values
		/*!		Function to set DestinationRoutingAddress type of argument destinationRoutingAddress for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		DestinationRoutingAddress* getdestinationRoutingAddress() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument alertingPattern for datatype ConnectArg
		*/
		bool setalertingPattern(capstd::OctetString* alertingPattern);

		//! Function to set values
		/*!		Function to set OctetString type of argument alertingPattern for datatype ConnectArg
		*/
		capstd::OctetString* setalertingPattern();

		//! Function to get values
		/*!		Function to set OctetString type of argument alertingPattern for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getalertingPattern() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument originalCalledPartyID for datatype ConnectArg
		*/
		bool setoriginalCalledPartyID(capstd::OctetString* originalCalledPartyID);

		//! Function to set values
		/*!		Function to set OctetString type of argument originalCalledPartyID for datatype ConnectArg
		*/
		capstd::OctetString* setoriginalCalledPartyID();

		//! Function to get values
		/*!		Function to set OctetString type of argument originalCalledPartyID for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getoriginalCalledPartyID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype ConnectArg
		*/
		bool setcarrier(capstd::OctetString* carrier);

		//! Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype ConnectArg
		*/
		capstd::OctetString* setcarrier();

		//! Function to get values
		/*!		Function to set OctetString type of argument carrier for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcarrier() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype ConnectArg
		*/
		bool setcallingPartysCategory(capstd::OctetString* callingPartysCategory);

		//! Function to set values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype ConnectArg
		*/
		capstd::OctetString* setcallingPartysCategory();

		//! Function to get values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallingPartysCategory() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument redirectingPartyID for datatype ConnectArg
		*/
		bool setredirectingPartyID(capstd::OctetString* redirectingPartyID);

		//! Function to set values
		/*!		Function to set OctetString type of argument redirectingPartyID for datatype ConnectArg
		*/
		capstd::OctetString* setredirectingPartyID();

		//! Function to get values
		/*!		Function to set OctetString type of argument redirectingPartyID for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getredirectingPartyID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument redirectionInformation for datatype ConnectArg
		*/
		bool setredirectionInformation(capstd::GENERIC* redirectionInformation);

		//! Function to set values
		/*!		Function to set GENERIC type of argument redirectionInformation for datatype ConnectArg
		*/
		capstd::GENERIC* setredirectionInformation();

		//! Function to get values
		/*!		Function to set GENERIC type of argument redirectionInformation for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getredirectionInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GenericNumbers type of argument genericNumbers for datatype ConnectArg
		*/
		bool setgenericNumbers(GenericNumbers* genericNumbers);

		//! Function to set values
		/*!		Function to set GenericNumbers type of argument genericNumbers for datatype ConnectArg
		*/
		GenericNumbers* setgenericNumbers();

		//! Function to get values
		/*!		Function to set GenericNumbers type of argument genericNumbers for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		GenericNumbers* getgenericNumbers() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ConnectArg
		*/
		bool setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo);

		//! Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ConnectArg
		*/
		ServiceInteractionIndicatorsTwo* setserviceInteractionIndicatorsTwo();

		//! Function to get values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		ServiceInteractionIndicatorsTwo* getserviceInteractionIndicatorsTwo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument chargeNumber for datatype ConnectArg
		*/
		bool setchargeNumber(capstd::OctetString* chargeNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument chargeNumber for datatype ConnectArg
		*/
		capstd::OctetString* setchargeNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument chargeNumber for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getchargeNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype ConnectArg
		*/
		bool setcug_Interlock(capstd::OctetString* cug_Interlock);

		//! Function to set values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype ConnectArg
		*/
		capstd::OctetString* setcug_Interlock();

		//! Function to get values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcug_Interlock() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument cug_OutgoingAccess for datatype ConnectArg
		*/
		bool setcug_OutgoingAccess(bool cug_OutgoingAccess);

		//! Function to set new values
		/*!		Function to set NULL type of argument cug_OutgoingAccess for datatype ConnectArg
		*/
		bool* setcug_OutgoingAccess();

		//! Function to get values
		/*!		Function to get NULL type of argument cug_OutgoingAccess for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		bool getcug_OutgoingAccess();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument suppressionOfAnnouncement for datatype ConnectArg
		*/
		bool setsuppressionOfAnnouncement(bool suppressionOfAnnouncement);

		//! Function to set new values
		/*!		Function to set NULL type of argument suppressionOfAnnouncement for datatype ConnectArg
		*/
		bool* setsuppressionOfAnnouncement();

		//! Function to get values
		/*!		Function to get NULL type of argument suppressionOfAnnouncement for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		bool getsuppressionOfAnnouncement();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument oCSIApplicable for datatype ConnectArg
		*/
		bool setoCSIApplicable(bool oCSIApplicable);

		//! Function to set new values
		/*!		Function to set NULL type of argument oCSIApplicable for datatype ConnectArg
		*/
		bool* setoCSIApplicable();

		//! Function to get values
		/*!		Function to get NULL type of argument oCSIApplicable for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		bool getoCSIApplicable();

		//!Function to set values
		/*!		Function to set OctetString type of argument naOliInfo for datatype ConnectArg
		*/
		bool setnaOliInfo(capstd::OctetString* naOliInfo);

		//! Function to set values
		/*!		Function to set OctetString type of argument naOliInfo for datatype ConnectArg
		*/
		capstd::OctetString* setnaOliInfo();

		//! Function to get values
		/*!		Function to set OctetString type of argument naOliInfo for datatype ConnectArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getnaOliInfo() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ConnectArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ConnectArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ConnectArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ConnectArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
