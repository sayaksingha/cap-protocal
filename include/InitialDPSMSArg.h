//  @(#) $Id: InitialDPSMSArg.h,v 1.1.2.3 2019/06/29 02:24:30 mrafi Exp $";

#ifndef INITIALDPSMSARG
#define INITIALDPSMSARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_InitialDPSMSArg
{
	InitialDPSMSArg_SERVICEKEY	=  1 << 0,
	InitialDPSMSArg_DESTINATIONSUBSCRIBERNUMBER	=  1 << 1,
	InitialDPSMSArg_CALLINGPARTYNUMBER	=  1 << 2,
	InitialDPSMSArg_EVENTTYPESMS	=  1 << 3,
	InitialDPSMSArg_IMSI	=  1 << 4,
	InitialDPSMSArg_LOCATIONINFORMATIONMSC	=  1 << 5,
	InitialDPSMSArg_LOCATIONINFORMATIONGPRS	=  1 << 6,
	InitialDPSMSArg_SMSCADDRESS	=  1 << 7,
	InitialDPSMSArg_TIMEANDTIMEZONE	=  1 << 8,
	InitialDPSMSArg_TPSHORTMESSAGESPECIFICINFO	=  1 << 9,
	InitialDPSMSArg_TPPROTOCOLIDENTIFIER	=  1 << 10,
	InitialDPSMSArg_TPDATACODINGSCHEME	=  1 << 11,
	InitialDPSMSArg_TPVALIDITYPERIOD	=  1 << 12,
	InitialDPSMSArg_EXTENSIONS	=  1 << 13,
	InitialDPSMSArg_SMSREFERENCENUMBER	=  1 << 14,
	InitialDPSMSArg_MSCADDRESS	=  1 << 15,
	InitialDPSMSArg_SGSN_NUMBER	=  1 << 16,
	InitialDPSMSArg_MS_CLASSMARK2	=  1 << 17,
	InitialDPSMSArg_GPRSMSCLASS	=  1 << 18,
	InitialDPSMSArg_IMEI	=  1 << 19,
	InitialDPSMSArg_CALLEDPARTYNUMBER	=  1 << 20,
	InitialDPSMSArg_TAG_NULL	=  0x0000
}InitialDPSMSArg_tags;

		//! Class Definition
		/*!		ClassName is InitialDPSMSArg
		*/
class InitialDPSMSArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::capstd::INTEGER*		mserviceKey;

		capstd::capstd::OctetString*		mdestinationSubscriberNumber;

		capstd::capstd::OctetString*		mcallingPartyNumber;

		EventTypeSMS*		meventTypeSMS;

		capstd::capstd::IMSI*		miMSI;

		LocationInformation*		mlocationInformationMSC;

		LocationInformationGPRS*		mlocationInformationGPRS;

		capstd::capstd::OctetString*		msMSCAddress;

		capstd::capstd::TimeAndTimezone*		mtimeAndTimezone;

		capstd::capstd::OctetString*		mtPShortMessageSpecificInfo;

		capstd::capstd::OctetString*		mtPProtocolIdentifier;

		capstd::capstd::OctetString*		mtPDataCodingScheme;

		capstd::capstd::OctetString*		mtPValidityPeriod;

		Extensions*		mextensions;

		capstd::capstd::CallReferenceNumber*		msmsReferenceNumber;

		capstd::capstd::OctetString*		mmscAddress;

		capstd::capstd::OctetString*		msgsn_Number;

		capstd::capstd::OctetString*		mms_Classmark2;

		GPRSMSClass*		mgPRSMSClass;

		capstd::capstd::OctetString*		miMEI;

		capstd::capstd::OctetString*		mcalledPartyNumber;


	public:
		InitialDPSMSArg();

		~InitialDPSMSArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype InitialDPSMSArg
		*/
		bool setserviceKey(capstd::capstd::INTEGER* serviceKey);

		//! Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype InitialDPSMSArg
		*/
		capstd::capstd::INTEGER* setserviceKey();

		//! Function to get values
		/*!		Function to set INTEGER type of argument serviceKey for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::INTEGER* getserviceKey() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument destinationSubscriberNumber for datatype InitialDPSMSArg
		*/
		bool setdestinationSubscriberNumber(capstd::capstd::OctetString* destinationSubscriberNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument destinationSubscriberNumber for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setdestinationSubscriberNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument destinationSubscriberNumber for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getdestinationSubscriberNumber() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callingPartyNumber for datatype InitialDPSMSArg
		*/
		bool setcallingPartyNumber(capstd::capstd::OctetString* callingPartyNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument callingPartyNumber for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setcallingPartyNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument callingPartyNumber for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getcallingPartyNumber() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set EventTypeSMS type of argument eventTypeSMS for datatype InitialDPSMSArg
		*/
		bool seteventTypeSMS(EventTypeSMS* eventTypeSMS);

		//! Function to set values
		/*!		Function to set EventTypeSMS type of argument eventTypeSMS for datatype InitialDPSMSArg
		*/
		EventTypeSMS* seteventTypeSMS();

		//! Function to get values
		/*!		Function to set EventTypeSMS type of argument eventTypeSMS for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		EventTypeSMS* geteventTypeSMS() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set IMSI type of argument iMSI for datatype InitialDPSMSArg
		*/
		bool setiMSI(capstd::capstd::IMSI* iMSI);

		//! Function to set values
		/*!		Function to set IMSI type of argument iMSI for datatype InitialDPSMSArg
		*/
		capstd::capstd::IMSI* setiMSI();

		//! Function to get values
		/*!		Function to set IMSI type of argument iMSI for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::IMSI* getiMSI() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set LocationInformation type of argument locationInformationMSC for datatype InitialDPSMSArg
		*/
		bool setlocationInformationMSC(LocationInformation* locationInformationMSC);

		//! Function to set values
		/*!		Function to set LocationInformation type of argument locationInformationMSC for datatype InitialDPSMSArg
		*/
		LocationInformation* setlocationInformationMSC();

		//! Function to get values
		/*!		Function to set LocationInformation type of argument locationInformationMSC for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		LocationInformation* getlocationInformationMSC() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set LocationInformationGPRS type of argument locationInformationGPRS for datatype InitialDPSMSArg
		*/
		bool setlocationInformationGPRS(LocationInformationGPRS* locationInformationGPRS);

		//! Function to set values
		/*!		Function to set LocationInformationGPRS type of argument locationInformationGPRS for datatype InitialDPSMSArg
		*/
		LocationInformationGPRS* setlocationInformationGPRS();

		//! Function to get values
		/*!		Function to set LocationInformationGPRS type of argument locationInformationGPRS for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		LocationInformationGPRS* getlocationInformationGPRS() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument sMSCAddress for datatype InitialDPSMSArg
		*/
		bool setsMSCAddress(capstd::capstd::OctetString* sMSCAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument sMSCAddress for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setsMSCAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument sMSCAddress for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getsMSCAddress() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set TimeAndTimezone type of argument timeAndTimezone for datatype InitialDPSMSArg
		*/
		bool settimeAndTimezone(capstd::capstd::TimeAndTimezone* timeAndTimezone);

		//! Function to set values
		/*!		Function to set TimeAndTimezone type of argument timeAndTimezone for datatype InitialDPSMSArg
		*/
		capstd::capstd::TimeAndTimezone* settimeAndTimezone();

		//! Function to get values
		/*!		Function to set TimeAndTimezone type of argument timeAndTimezone for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::TimeAndTimezone* gettimeAndTimezone() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument tPShortMessageSpecificInfo for datatype InitialDPSMSArg
		*/
		bool settPShortMessageSpecificInfo(capstd::capstd::OctetString* tPShortMessageSpecificInfo);

		//! Function to set values
		/*!		Function to set OctetString type of argument tPShortMessageSpecificInfo for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* settPShortMessageSpecificInfo();

		//! Function to get values
		/*!		Function to set OctetString type of argument tPShortMessageSpecificInfo for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* gettPShortMessageSpecificInfo() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument tPProtocolIdentifier for datatype InitialDPSMSArg
		*/
		bool settPProtocolIdentifier(capstd::capstd::OctetString* tPProtocolIdentifier);

		//! Function to set values
		/*!		Function to set OctetString type of argument tPProtocolIdentifier for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* settPProtocolIdentifier();

		//! Function to get values
		/*!		Function to set OctetString type of argument tPProtocolIdentifier for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* gettPProtocolIdentifier() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument tPDataCodingScheme for datatype InitialDPSMSArg
		*/
		bool settPDataCodingScheme(capstd::capstd::OctetString* tPDataCodingScheme);

		//! Function to set values
		/*!		Function to set OctetString type of argument tPDataCodingScheme for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* settPDataCodingScheme();

		//! Function to get values
		/*!		Function to set OctetString type of argument tPDataCodingScheme for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* gettPDataCodingScheme() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument tPValidityPeriod for datatype InitialDPSMSArg
		*/
		bool settPValidityPeriod(capstd::capstd::OctetString* tPValidityPeriod);

		//! Function to set values
		/*!		Function to set OctetString type of argument tPValidityPeriod for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* settPValidityPeriod();

		//! Function to get values
		/*!		Function to set OctetString type of argument tPValidityPeriod for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* gettPValidityPeriod() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype InitialDPSMSArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype InitialDPSMSArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set CallReferenceNumber type of argument smsReferenceNumber for datatype InitialDPSMSArg
		*/
		bool setsmsReferenceNumber(capstd::capstd::CallReferenceNumber* smsReferenceNumber);

		//! Function to set values
		/*!		Function to set CallReferenceNumber type of argument smsReferenceNumber for datatype InitialDPSMSArg
		*/
		capstd::capstd::CallReferenceNumber* setsmsReferenceNumber();

		//! Function to get values
		/*!		Function to set CallReferenceNumber type of argument smsReferenceNumber for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::CallReferenceNumber* getsmsReferenceNumber() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument mscAddress for datatype InitialDPSMSArg
		*/
		bool setmscAddress(capstd::capstd::OctetString* mscAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument mscAddress for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setmscAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument mscAddress for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getmscAddress() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument sgsn_Number for datatype InitialDPSMSArg
		*/
		bool setsgsn_Number(capstd::capstd::OctetString* sgsn_Number);

		//! Function to set values
		/*!		Function to set OctetString type of argument sgsn_Number for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setsgsn_Number();

		//! Function to get values
		/*!		Function to set OctetString type of argument sgsn_Number for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getsgsn_Number() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument ms_Classmark2 for datatype InitialDPSMSArg
		*/
		bool setms_Classmark2(capstd::capstd::OctetString* ms_Classmark2);

		//! Function to set values
		/*!		Function to set OctetString type of argument ms_Classmark2 for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setms_Classmark2();

		//! Function to get values
		/*!		Function to set OctetString type of argument ms_Classmark2 for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getms_Classmark2() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set GPRSMSClass type of argument gPRSMSClass for datatype InitialDPSMSArg
		*/
		bool setgPRSMSClass(GPRSMSClass* gPRSMSClass);

		//! Function to set values
		/*!		Function to set GPRSMSClass type of argument gPRSMSClass for datatype InitialDPSMSArg
		*/
		GPRSMSClass* setgPRSMSClass();

		//! Function to get values
		/*!		Function to set GPRSMSClass type of argument gPRSMSClass for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		GPRSMSClass* getgPRSMSClass() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument iMEI for datatype InitialDPSMSArg
		*/
		bool setiMEI(capstd::capstd::OctetString* iMEI);

		//! Function to set values
		/*!		Function to set OctetString type of argument iMEI for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setiMEI();

		//! Function to get values
		/*!		Function to set OctetString type of argument iMEI for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getiMEI() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument calledPartyNumber for datatype InitialDPSMSArg
		*/
		bool setcalledPartyNumber(capstd::capstd::OctetString* calledPartyNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument calledPartyNumber for datatype InitialDPSMSArg
		*/
		capstd::capstd::OctetString* setcalledPartyNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument calledPartyNumber for datatype InitialDPSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getcalledPartyNumber() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype InitialDPSMSArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype InitialDPSMSArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype InitialDPSMSArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags InitialDPSMSArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
