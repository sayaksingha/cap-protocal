#ifndef PHASE3_INITIALDPARG
#define PHASE3_INITIALDPARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_InitialDPArg
{
	InitialDPArg_SERVICEKEY	=  1 << 0,
	InitialDPArg_CALLEDPARTYNUMBER	=  1 << 1,
	InitialDPArg_CALLINGPARTYNUMBER	=  1 << 2,
	InitialDPArg_CALLINGPARTYSCATEGORY	=  1 << 3,
	InitialDPArg_CGENCOUNTERED	=  1 << 4,
	InitialDPArg_IPSSPCAPABILITIES	=  1 << 5,
	InitialDPArg_LOCATIONNUMBER	=  1 << 6,
	InitialDPArg_ORIGINALCALLEDPARTYID	=  1 << 7,
	InitialDPArg_EXTENSIONS	=  1 << 8,
	InitialDPArg_HIGHLAYERCOMPATIBILITY	=  1 << 9,
	InitialDPArg_ADDITIONALCALLINGPARTYNUMBER	=  1 << 10,
	InitialDPArg_BEARERCAPABILITY	=  1 << 11,
	InitialDPArg_EVENTTYPEBCSM	=  1 << 12,
	InitialDPArg_REDIRECTINGPARTYID	=  1 << 13,
	InitialDPArg_REDIRECTIONINFORMATION	=  1 << 14,
	InitialDPArg_CAUSE	=  1 << 15,
	InitialDPArg_SERVICEINTERACTIONINDICATORSTWO	=  1 << 16,
	InitialDPArg_CARRIER	=  1 << 17,
	InitialDPArg_CUG_INDEX	=  1 << 18,
	InitialDPArg_CUG_INTERLOCK	=  1 << 19,
	InitialDPArg_CUG_OUTGOINGACCESS	=  1 << 20,
	InitialDPArg_IMSI	=  1 << 21,
	InitialDPArg_SUBSCRIBERSTATE	=  1 << 22,
	InitialDPArg_LOCATIONINFORMATION	=  1 << 23,
	InitialDPArg_EXT_BASICSERVICECODE	=  1 << 24,
	InitialDPArg_CALLREFERENCENUMBER	=  1 << 25,
	InitialDPArg_MSCADDRESS	=  1 << 26,
	InitialDPArg_CALLEDPARTYBCDNUMBER	=  1 << 27,
	InitialDPArg_TIMEANDTIMEZONE	=  1 << 28,
	InitialDPArg_GSM_FORWARDINGPENDING	=  1 << 29,
	InitialDPArg_INITIALDPARGEXTENSION	=  1 << 30,
	InitialDPArg_TAG_NULL	=  0x0000
}InitialDPArg_tags;

		//! Class Definition
		/*!		ClassName is InitialDPArg
		*/
class InitialDPArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mserviceKey;

		capstd::OctetString*		mcalledPartyNumber;

		capstd::OctetString*		mcallingPartyNumber;

		capstd::OctetString*		mcallingPartysCategory;

		CGEncountered*		mcGEncountered;

		capstd::OctetString*		miPSSPCapabilities;

		capstd::OctetString*		mlocationNumber;

		capstd::OctetString*		moriginalCalledPartyID;

		Extensions*		mextensions;

		capstd::OctetString*		mhighLayerCompatibility;

		capstd::OctetString*		madditionalCallingPartyNumber;

		BearerCapability*		mbearerCapability;

		EventTypeBCSM*		meventTypeBCSM;

		capstd::OctetString*		mredirectingPartyID;

		capstd::GENERIC*		mredirectionInformation;

		capstd::GENERIC*		mcause;

		ServiceInteractionIndicatorsTwo*		mserviceInteractionIndicatorsTwo;

		capstd::OctetString*		mcarrier;

		capstd::INTEGER*		mcug_Index;

		capstd::OctetString*		mcug_Interlock;

		bool 		mcug_OutgoingAccess;

		bool 		mNullcug_OutgoingAccess;

		capstd::IMSI*		miMSI;

		SubscriberState*		msubscriberState;

		LocationInformation*		mlocationInformation;

		Ext_BasicServiceCode*		mext_basicServiceCode;

		capstd::CallReferenceNumber*		mcallReferenceNumber;

		capstd::OctetString*		mmscAddress;

		capstd::OctetString*		mcalledPartyBCDNumber;

		capstd::TimeAndTimezone*		mtimeAndTimezone;

		bool 		mgsm_ForwardingPending;

		bool 		mNullgsm_ForwardingPending;

		InitialDPArgExtension*		minitialDPArgExtension;


	public:
		InitialDPArg();

		~InitialDPArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype InitialDPArg
		*/
		bool setserviceKey(capstd::INTEGER* serviceKey);

		//! Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype InitialDPArg
		*/
		capstd::INTEGER* setserviceKey();

		//! Function to get values
		/*!		Function to set INTEGER type of argument serviceKey for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getserviceKey() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument calledPartyNumber for datatype InitialDPArg
		*/
		bool setcalledPartyNumber(capstd::OctetString* calledPartyNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument calledPartyNumber for datatype InitialDPArg
		*/
		capstd::OctetString* setcalledPartyNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument calledPartyNumber for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcalledPartyNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callingPartyNumber for datatype InitialDPArg
		*/
		bool setcallingPartyNumber(capstd::OctetString* callingPartyNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument callingPartyNumber for datatype InitialDPArg
		*/
		capstd::OctetString* setcallingPartyNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument callingPartyNumber for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallingPartyNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype InitialDPArg
		*/
		bool setcallingPartysCategory(capstd::OctetString* callingPartysCategory);

		//! Function to set values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype InitialDPArg
		*/
		capstd::OctetString* setcallingPartysCategory();

		//! Function to get values
		/*!		Function to set OctetString type of argument callingPartysCategory for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallingPartysCategory() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set CGEncountered type of argument cGEncountered for datatype InitialDPArg
		*/
		bool setcGEncountered(CGEncountered* cGEncountered);

		//! Function to set values
		/*!		Function to set CGEncountered type of argument cGEncountered for datatype InitialDPArg
		*/
		CGEncountered* setcGEncountered();

		//! Function to get values
		/*!		Function to set CGEncountered type of argument cGEncountered for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		CGEncountered* getcGEncountered() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument iPSSPCapabilities for datatype InitialDPArg
		*/
		bool setiPSSPCapabilities(capstd::OctetString* iPSSPCapabilities);

		//! Function to set values
		/*!		Function to set OctetString type of argument iPSSPCapabilities for datatype InitialDPArg
		*/
		capstd::OctetString* setiPSSPCapabilities();

		//! Function to get values
		/*!		Function to set OctetString type of argument iPSSPCapabilities for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getiPSSPCapabilities() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument locationNumber for datatype InitialDPArg
		*/
		bool setlocationNumber(capstd::OctetString* locationNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument locationNumber for datatype InitialDPArg
		*/
		capstd::OctetString* setlocationNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument locationNumber for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getlocationNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument originalCalledPartyID for datatype InitialDPArg
		*/
		bool setoriginalCalledPartyID(capstd::OctetString* originalCalledPartyID);

		//! Function to set values
		/*!		Function to set OctetString type of argument originalCalledPartyID for datatype InitialDPArg
		*/
		capstd::OctetString* setoriginalCalledPartyID();

		//! Function to get values
		/*!		Function to set OctetString type of argument originalCalledPartyID for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getoriginalCalledPartyID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype InitialDPArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype InitialDPArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument highLayerCompatibility for datatype InitialDPArg
		*/
		bool sethighLayerCompatibility(capstd::OctetString* highLayerCompatibility);

		//! Function to set values
		/*!		Function to set OctetString type of argument highLayerCompatibility for datatype InitialDPArg
		*/
		capstd::OctetString* sethighLayerCompatibility();

		//! Function to get values
		/*!		Function to set OctetString type of argument highLayerCompatibility for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* gethighLayerCompatibility() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument additionalCallingPartyNumber for datatype InitialDPArg
		*/
		bool setadditionalCallingPartyNumber(capstd::OctetString* additionalCallingPartyNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument additionalCallingPartyNumber for datatype InitialDPArg
		*/
		capstd::OctetString* setadditionalCallingPartyNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument additionalCallingPartyNumber for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getadditionalCallingPartyNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set BearerCapability type of argument bearerCapability for datatype InitialDPArg
		*/
		bool setbearerCapability(BearerCapability* bearerCapability);

		//! Function to set values
		/*!		Function to set BearerCapability type of argument bearerCapability for datatype InitialDPArg
		*/
		BearerCapability* setbearerCapability();

		//! Function to get values
		/*!		Function to set BearerCapability type of argument bearerCapability for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		BearerCapability* getbearerCapability() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype InitialDPArg
		*/
		bool seteventTypeBCSM(EventTypeBCSM* eventTypeBCSM);

		//! Function to set values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype InitialDPArg
		*/
		EventTypeBCSM* seteventTypeBCSM();

		//! Function to get values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		EventTypeBCSM* geteventTypeBCSM() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument redirectingPartyID for datatype InitialDPArg
		*/
		bool setredirectingPartyID(capstd::OctetString* redirectingPartyID);

		//! Function to set values
		/*!		Function to set OctetString type of argument redirectingPartyID for datatype InitialDPArg
		*/
		capstd::OctetString* setredirectingPartyID();

		//! Function to get values
		/*!		Function to set OctetString type of argument redirectingPartyID for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getredirectingPartyID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument redirectionInformation for datatype InitialDPArg
		*/
		bool setredirectionInformation(capstd::GENERIC* redirectionInformation);

		//! Function to set values
		/*!		Function to set GENERIC type of argument redirectionInformation for datatype InitialDPArg
		*/
		capstd::GENERIC* setredirectionInformation();

		//! Function to get values
		/*!		Function to set GENERIC type of argument redirectionInformation for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getredirectionInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument cause for datatype InitialDPArg
		*/
		bool setcause(capstd::GENERIC* cause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument cause for datatype InitialDPArg
		*/
		capstd::GENERIC* setcause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument cause for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getcause() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype InitialDPArg
		*/
		bool setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo);

		//! Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype InitialDPArg
		*/
		ServiceInteractionIndicatorsTwo* setserviceInteractionIndicatorsTwo();

		//! Function to get values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		ServiceInteractionIndicatorsTwo* getserviceInteractionIndicatorsTwo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype InitialDPArg
		*/
		bool setcarrier(capstd::OctetString* carrier);

		//! Function to set values
		/*!		Function to set OctetString type of argument carrier for datatype InitialDPArg
		*/
		capstd::OctetString* setcarrier();

		//! Function to get values
		/*!		Function to set OctetString type of argument carrier for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcarrier() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument cug_Index for datatype InitialDPArg
		*/
		bool setcug_Index(capstd::INTEGER* cug_Index);

		//! Function to set values
		/*!		Function to set INTEGER type of argument cug_Index for datatype InitialDPArg
		*/
		capstd::INTEGER* setcug_Index();

		//! Function to get values
		/*!		Function to set INTEGER type of argument cug_Index for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getcug_Index() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype InitialDPArg
		*/
		bool setcug_Interlock(capstd::OctetString* cug_Interlock);

		//! Function to set values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype InitialDPArg
		*/
		capstd::OctetString* setcug_Interlock();

		//! Function to get values
		/*!		Function to set OctetString type of argument cug_Interlock for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcug_Interlock() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument cug_OutgoingAccess for datatype InitialDPArg
		*/
		bool setcug_OutgoingAccess(bool cug_OutgoingAccess);

		//! Function to set new values
		/*!		Function to set NULL type of argument cug_OutgoingAccess for datatype InitialDPArg
		*/
		bool* setcug_OutgoingAccess();

		//! Function to get values
		/*!		Function to get NULL type of argument cug_OutgoingAccess for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		bool getcug_OutgoingAccess();

		//!Function to set values
		/*!		Function to set IMSI type of argument iMSI for datatype InitialDPArg
		*/
		bool setiMSI(capstd::IMSI* iMSI);

		//! Function to set values
		/*!		Function to set IMSI type of argument iMSI for datatype InitialDPArg
		*/
		capstd::IMSI* setiMSI();

		//! Function to get values
		/*!		Function to set IMSI type of argument iMSI for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::IMSI* getiMSI() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set SubscriberState type of argument subscriberState for datatype InitialDPArg
		*/
		bool setsubscriberState(SubscriberState* subscriberState);

		//! Function to set values
		/*!		Function to set SubscriberState type of argument subscriberState for datatype InitialDPArg
		*/
		SubscriberState* setsubscriberState();

		//! Function to get values
		/*!		Function to set SubscriberState type of argument subscriberState for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		SubscriberState* getsubscriberState() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set LocationInformation type of argument locationInformation for datatype InitialDPArg
		*/
		bool setlocationInformation(LocationInformation* locationInformation);

		//! Function to set values
		/*!		Function to set LocationInformation type of argument locationInformation for datatype InitialDPArg
		*/
		LocationInformation* setlocationInformation();

		//! Function to get values
		/*!		Function to set LocationInformation type of argument locationInformation for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		LocationInformation* getlocationInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Ext_BasicServiceCode type of argument ext_basicServiceCode for datatype InitialDPArg
		*/
		bool setext_basicServiceCode(Ext_BasicServiceCode* ext_basicServiceCode);

		//! Function to set values
		/*!		Function to set Ext_BasicServiceCode type of argument ext_basicServiceCode for datatype InitialDPArg
		*/
		Ext_BasicServiceCode* setext_basicServiceCode();

		//! Function to get values
		/*!		Function to set Ext_BasicServiceCode type of argument ext_basicServiceCode for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		Ext_BasicServiceCode* getext_basicServiceCode() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set CallReferenceNumber type of argument callReferenceNumber for datatype InitialDPArg
		*/
		bool setcallReferenceNumber(capstd::CallReferenceNumber* callReferenceNumber);

		//! Function to set values
		/*!		Function to set CallReferenceNumber type of argument callReferenceNumber for datatype InitialDPArg
		*/
		capstd::CallReferenceNumber* setcallReferenceNumber();

		//! Function to get values
		/*!		Function to set CallReferenceNumber type of argument callReferenceNumber for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::CallReferenceNumber* getcallReferenceNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument mscAddress for datatype InitialDPArg
		*/
		bool setmscAddress(capstd::OctetString* mscAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument mscAddress for datatype InitialDPArg
		*/
		capstd::OctetString* setmscAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument mscAddress for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmscAddress() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument calledPartyBCDNumber for datatype InitialDPArg
		*/
		bool setcalledPartyBCDNumber(capstd::OctetString* calledPartyBCDNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument calledPartyBCDNumber for datatype InitialDPArg
		*/
		capstd::OctetString* setcalledPartyBCDNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument calledPartyBCDNumber for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcalledPartyBCDNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TimeAndTimezone type of argument timeAndTimezone for datatype InitialDPArg
		*/
		bool settimeAndTimezone(capstd::TimeAndTimezone* timeAndTimezone);

		//! Function to set values
		/*!		Function to set TimeAndTimezone type of argument timeAndTimezone for datatype InitialDPArg
		*/
		capstd::TimeAndTimezone* settimeAndTimezone();

		//! Function to get values
		/*!		Function to set TimeAndTimezone type of argument timeAndTimezone for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::TimeAndTimezone* gettimeAndTimezone() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument gsm_ForwardingPending for datatype InitialDPArg
		*/
		bool setgsm_ForwardingPending(bool gsm_ForwardingPending);

		//! Function to set new values
		/*!		Function to set NULL type of argument gsm_ForwardingPending for datatype InitialDPArg
		*/
		bool* setgsm_ForwardingPending();

		//! Function to get values
		/*!		Function to get NULL type of argument gsm_ForwardingPending for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		bool getgsm_ForwardingPending();

		//!Function to set values
		/*!		Function to set InitialDPArgExtension type of argument initialDPArgExtension for datatype InitialDPArg
		*/
		bool setinitialDPArgExtension(InitialDPArgExtension* initialDPArgExtension);

		//! Function to set values
		/*!		Function to set InitialDPArgExtension type of argument initialDPArgExtension for datatype InitialDPArg
		*/
		InitialDPArgExtension* setinitialDPArgExtension();

		//! Function to get values
		/*!		Function to set InitialDPArgExtension type of argument initialDPArgExtension for datatype InitialDPArg
		Throws exception of which type and Summary of Exception
		*/
		InitialDPArgExtension* getinitialDPArgExtension() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype InitialDPArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype InitialDPArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype InitialDPArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags InitialDPArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
