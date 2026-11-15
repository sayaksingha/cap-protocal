static const char *id = " @(#) $Id: InitialDPSMSArg.cc,v 1.1.2.3 2019/06/29 02:24:31 mrafi Exp $";

#include "InitialDPSMSArg.h"

using namespace capphase3;

InitialDPSMSArg::InitialDPSMSArg()
{
	mserviceKey = NULL;
	mdestinationSubscriberNumber = NULL;
	mcallingPartyNumber = NULL;
	meventTypeSMS = NULL;
	miMSI = NULL;
	mlocationInformationMSC = NULL;
	mlocationInformationGPRS = NULL;
	msMSCAddress = NULL;
	mtimeAndTimezone = NULL;
	mtPShortMessageSpecificInfo = NULL;
	mtPProtocolIdentifier = NULL;
	mtPDataCodingScheme = NULL;
	mtPValidityPeriod = NULL;
	mextensions = NULL;
	msmsReferenceNumber = NULL;
	mmscAddress = NULL;
	msgsn_Number = NULL;
	mms_Classmark2 = NULL;
	mgPRSMSClass = NULL;
	miMEI = NULL;
	mcalledPartyNumber = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X0083, 0X0084, 0X00A5, 0X00A6, 0X0087, 0X0088, 0X0089, 0X008A, 0X008B, 0X008C, 0X00AD, 0X008E, 0X008F, 0X0090, 0X0091, 0X00B2, 0X0093, 0X0094};
	mTagOptional = {false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
}

InitialDPSMSArg::~InitialDPSMSArg()
{
	if(mserviceKey != NULL)
		delete mserviceKey;
	if(mdestinationSubscriberNumber != NULL)
		delete mdestinationSubscriberNumber;
	if(mcallingPartyNumber != NULL)
		delete mcallingPartyNumber;
	if(meventTypeSMS != NULL)
		delete meventTypeSMS;
	if(miMSI != NULL)
		delete miMSI;
	if(mlocationInformationMSC != NULL)
		delete mlocationInformationMSC;
	if(mlocationInformationGPRS != NULL)
		delete mlocationInformationGPRS;
	if(msMSCAddress != NULL)
		delete msMSCAddress;
	if(mtimeAndTimezone != NULL)
		delete mtimeAndTimezone;
	if(mtPShortMessageSpecificInfo != NULL)
		delete mtPShortMessageSpecificInfo;
	if(mtPProtocolIdentifier != NULL)
		delete mtPProtocolIdentifier;
	if(mtPDataCodingScheme != NULL)
		delete mtPDataCodingScheme;
	if(mtPValidityPeriod != NULL)
		delete mtPValidityPeriod;
	if(mextensions != NULL)
		delete mextensions;
	if(msmsReferenceNumber != NULL)
		delete msmsReferenceNumber;
	if(mmscAddress != NULL)
		delete mmscAddress;
	if(msgsn_Number != NULL)
		delete msgsn_Number;
	if(mms_Classmark2 != NULL)
		delete mms_Classmark2;
	if(mgPRSMSClass != NULL)
		delete mgPRSMSClass;
	if(miMEI != NULL)
		delete miMEI;
	if(mcalledPartyNumber != NULL)
		delete mcalledPartyNumber;
}

capstd::capstd::INTEGER* InitialDPSMSArg::setserviceKey(){
	if(mserviceKey == NULL)
	{
		mserviceKey = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= InitialDPSMSArg_SERVICEKEY;
		return mserviceKey;
	}
	else
		return mserviceKey;

}

bool InitialDPSMSArg::setserviceKey(capstd::capstd::INTEGER* serviceKey){
	if(mserviceKey == NULL)
	{
		return -1;
	}
	else
	{
		mserviceKey = serviceKey;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setdestinationSubscriberNumber(){
	if(mdestinationSubscriberNumber == NULL)
	{
		mdestinationSubscriberNumber = new capstd::OctetString(1, 41);
		mTagsPresent |= InitialDPSMSArg_DESTINATIONSUBSCRIBERNUMBER;
		return mdestinationSubscriberNumber;
	}
	else
		return mdestinationSubscriberNumber;

}

bool InitialDPSMSArg::setdestinationSubscriberNumber(capstd::capstd::OctetString* destinationSubscriberNumber){
	if(mdestinationSubscriberNumber == NULL)
	{
		return -1;
	}
	else
	{
		mdestinationSubscriberNumber = destinationSubscriberNumber;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setcallingPartyNumber(){
	if(mcallingPartyNumber == NULL)
	{
		mcallingPartyNumber = new capstd::OctetString(1, 20);
		mTagsPresent |= InitialDPSMSArg_CALLINGPARTYNUMBER;
		return mcallingPartyNumber;
	}
	else
		return mcallingPartyNumber;

}

bool InitialDPSMSArg::setcallingPartyNumber(capstd::capstd::OctetString* callingPartyNumber){
	if(mcallingPartyNumber == NULL)
	{
		return -1;
	}
	else
	{
		mcallingPartyNumber = callingPartyNumber;
		return true;
	}

}

EventTypeSMS* InitialDPSMSArg::seteventTypeSMS(){
	if(meventTypeSMS == NULL)
	{
		meventTypeSMS = new EventTypeSMS();
		mTagsPresent |= InitialDPSMSArg_EVENTTYPESMS;
		return meventTypeSMS;
	}
	else
		return meventTypeSMS;

}

bool InitialDPSMSArg::seteventTypeSMS(EventTypeSMS* eventTypeSMS){
	if(meventTypeSMS == NULL)
	{
		return -1;
	}
	else
	{
		meventTypeSMS = eventTypeSMS;
		return true;
	}

}

capstd::capstd::IMSI* InitialDPSMSArg::setiMSI(){
	if(miMSI == NULL)
	{
		miMSI = new capstd::IMSI();
		mTagsPresent |= InitialDPSMSArg_IMSI;
		return miMSI;
	}
	else
		return miMSI;

}

bool InitialDPSMSArg::setiMSI(capstd::capstd::IMSI* iMSI){
	if(miMSI == NULL)
	{
		return -1;
	}
	else
	{
		miMSI = iMSI;
		return true;
	}

}

LocationInformation* InitialDPSMSArg::setlocationInformationMSC(){
	if(mlocationInformationMSC == NULL)
	{
		mlocationInformationMSC = new LocationInformation();
		mTagsPresent |= InitialDPSMSArg_LOCATIONINFORMATIONMSC;
		return mlocationInformationMSC;
	}
	else
		return mlocationInformationMSC;

}

bool InitialDPSMSArg::setlocationInformationMSC(LocationInformation* locationInformationMSC){
	if(mlocationInformationMSC == NULL)
	{
		return -1;
	}
	else
	{
		mlocationInformationMSC = locationInformationMSC;
		return true;
	}

}

LocationInformationGPRS* InitialDPSMSArg::setlocationInformationGPRS(){
	if(mlocationInformationGPRS == NULL)
	{
		mlocationInformationGPRS = new LocationInformationGPRS();
		mTagsPresent |= InitialDPSMSArg_LOCATIONINFORMATIONGPRS;
		return mlocationInformationGPRS;
	}
	else
		return mlocationInformationGPRS;

}

bool InitialDPSMSArg::setlocationInformationGPRS(LocationInformationGPRS* locationInformationGPRS){
	if(mlocationInformationGPRS == NULL)
	{
		return -1;
	}
	else
	{
		mlocationInformationGPRS = locationInformationGPRS;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setsMSCAddress(){
	if(msMSCAddress == NULL)
	{
		msMSCAddress = new capstd::OctetString(1, 20);
		mTagsPresent |= InitialDPSMSArg_SMSCADDRESS;
		return msMSCAddress;
	}
	else
		return msMSCAddress;

}

bool InitialDPSMSArg::setsMSCAddress(capstd::capstd::OctetString* sMSCAddress){
	if(msMSCAddress == NULL)
	{
		return -1;
	}
	else
	{
		msMSCAddress = sMSCAddress;
		return true;
	}

}

capstd::capstd::TimeAndTimezone* InitialDPSMSArg::settimeAndTimezone(){
	if(mtimeAndTimezone == NULL)
	{
		mtimeAndTimezone = new capstd::TimeAndTimezone();
		mTagsPresent |= InitialDPSMSArg_TIMEANDTIMEZONE;
		return mtimeAndTimezone;
	}
	else
		return mtimeAndTimezone;

}

bool InitialDPSMSArg::settimeAndTimezone(capstd::capstd::TimeAndTimezone* timeAndTimezone){
	if(mtimeAndTimezone == NULL)
	{
		return -1;
	}
	else
	{
		mtimeAndTimezone = timeAndTimezone;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::settPShortMessageSpecificInfo(){
	if(mtPShortMessageSpecificInfo == NULL)
	{
		mtPShortMessageSpecificInfo = new capstd::OctetString(1, 1);
		mTagsPresent |= InitialDPSMSArg_TPSHORTMESSAGESPECIFICINFO;
		return mtPShortMessageSpecificInfo;
	}
	else
		return mtPShortMessageSpecificInfo;

}

bool InitialDPSMSArg::settPShortMessageSpecificInfo(capstd::capstd::OctetString* tPShortMessageSpecificInfo){
	if(mtPShortMessageSpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		mtPShortMessageSpecificInfo = tPShortMessageSpecificInfo;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::settPProtocolIdentifier(){
	if(mtPProtocolIdentifier == NULL)
	{
		mtPProtocolIdentifier = new capstd::OctetString(1, 1);
		mTagsPresent |= InitialDPSMSArg_TPPROTOCOLIDENTIFIER;
		return mtPProtocolIdentifier;
	}
	else
		return mtPProtocolIdentifier;

}

bool InitialDPSMSArg::settPProtocolIdentifier(capstd::capstd::OctetString* tPProtocolIdentifier){
	if(mtPProtocolIdentifier == NULL)
	{
		return -1;
	}
	else
	{
		mtPProtocolIdentifier = tPProtocolIdentifier;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::settPDataCodingScheme(){
	if(mtPDataCodingScheme == NULL)
	{
		mtPDataCodingScheme = new capstd::OctetString(1, 1);
		mTagsPresent |= InitialDPSMSArg_TPDATACODINGSCHEME;
		return mtPDataCodingScheme;
	}
	else
		return mtPDataCodingScheme;

}

bool InitialDPSMSArg::settPDataCodingScheme(capstd::capstd::OctetString* tPDataCodingScheme){
	if(mtPDataCodingScheme == NULL)
	{
		return -1;
	}
	else
	{
		mtPDataCodingScheme = tPDataCodingScheme;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::settPValidityPeriod(){
	if(mtPValidityPeriod == NULL)
	{
		mtPValidityPeriod = new capstd::OctetString(1, 7);
		mTagsPresent |= InitialDPSMSArg_TPVALIDITYPERIOD;
		return mtPValidityPeriod;
	}
	else
		return mtPValidityPeriod;

}

bool InitialDPSMSArg::settPValidityPeriod(capstd::capstd::OctetString* tPValidityPeriod){
	if(mtPValidityPeriod == NULL)
	{
		return -1;
	}
	else
	{
		mtPValidityPeriod = tPValidityPeriod;
		return true;
	}

}

Extensions* InitialDPSMSArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= InitialDPSMSArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool InitialDPSMSArg::setextensions(Extensions* extensions){
	if(mextensions == NULL)
	{
		return -1;
	}
	else
	{
		mextensions = extensions;
		return true;
	}

}

capstd::capstd::CallReferenceNumber* InitialDPSMSArg::setsmsReferenceNumber(){
	if(msmsReferenceNumber == NULL)
	{
		msmsReferenceNumber = new capstd::CallReferenceNumber();
		mTagsPresent |= InitialDPSMSArg_SMSREFERENCENUMBER;
		return msmsReferenceNumber;
	}
	else
		return msmsReferenceNumber;

}

bool InitialDPSMSArg::setsmsReferenceNumber(capstd::capstd::CallReferenceNumber* smsReferenceNumber){
	if(msmsReferenceNumber == NULL)
	{
		return -1;
	}
	else
	{
		msmsReferenceNumber = smsReferenceNumber;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setmscAddress(){
	if(mmscAddress == NULL)
	{
		mmscAddress = new capstd::OctetString(1, 20);
		mTagsPresent |= InitialDPSMSArg_MSCADDRESS;
		return mmscAddress;
	}
	else
		return mmscAddress;

}

bool InitialDPSMSArg::setmscAddress(capstd::capstd::OctetString* mscAddress){
	if(mmscAddress == NULL)
	{
		return -1;
	}
	else
	{
		mmscAddress = mscAddress;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setsgsn_Number(){
	if(msgsn_Number == NULL)
	{
		msgsn_Number = new capstd::OctetString(1, 20);
		mTagsPresent |= InitialDPSMSArg_SGSN_NUMBER;
		return msgsn_Number;
	}
	else
		return msgsn_Number;

}

bool InitialDPSMSArg::setsgsn_Number(capstd::capstd::OctetString* sgsn_Number){
	if(msgsn_Number == NULL)
	{
		return -1;
	}
	else
	{
		msgsn_Number = sgsn_Number;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setms_Classmark2(){
	if(mms_Classmark2 == NULL)
	{
		mms_Classmark2 = new capstd::OctetString(3, 3);
		mTagsPresent |= InitialDPSMSArg_MS_CLASSMARK2;
		return mms_Classmark2;
	}
	else
		return mms_Classmark2;

}

bool InitialDPSMSArg::setms_Classmark2(capstd::capstd::OctetString* ms_Classmark2){
	if(mms_Classmark2 == NULL)
	{
		return -1;
	}
	else
	{
		mms_Classmark2 = ms_Classmark2;
		return true;
	}

}

GPRSMSClass* InitialDPSMSArg::setgPRSMSClass(){
	if(mgPRSMSClass == NULL)
	{
		mgPRSMSClass = new GPRSMSClass();
		mTagsPresent |= InitialDPSMSArg_GPRSMSCLASS;
		return mgPRSMSClass;
	}
	else
		return mgPRSMSClass;

}

bool InitialDPSMSArg::setgPRSMSClass(GPRSMSClass* gPRSMSClass){
	if(mgPRSMSClass == NULL)
	{
		return -1;
	}
	else
	{
		mgPRSMSClass = gPRSMSClass;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setiMEI(){
	if(miMEI == NULL)
	{
		miMEI = new capstd::OctetString;
		mTagsPresent |= InitialDPSMSArg_IMEI;
		return miMEI;
	}
	else
		return miMEI;

}

bool InitialDPSMSArg::setiMEI(capstd::capstd::OctetString* iMEI){
	if(miMEI == NULL)
	{
		return -1;
	}
	else
	{
		miMEI = iMEI;
		return true;
	}

}

capstd::capstd::OctetString* InitialDPSMSArg::setcalledPartyNumber(){
	if(mcalledPartyNumber == NULL)
	{
		mcalledPartyNumber = new capstd::OctetString(1, 20);
		mTagsPresent |= InitialDPSMSArg_CALLEDPARTYNUMBER;
		return mcalledPartyNumber;
	}
	else
		return mcalledPartyNumber;

}

bool InitialDPSMSArg::setcalledPartyNumber(capstd::capstd::OctetString* calledPartyNumber){
	if(mcalledPartyNumber == NULL)
	{
		return -1;
	}
	else
	{
		mcalledPartyNumber = calledPartyNumber;
		return true;
	}

}

capstd::capstd::INTEGER* InitialDPSMSArg::getserviceKey()  { // //{//throw(const char*)
	if(NULL == mserviceKey)
		throw("Object serviceKey is NULL");
	else
		return mserviceKey;
}

capstd::capstd::OctetString* InitialDPSMSArg::getdestinationSubscriberNumber()  { // //{//throw(const char*)
	if(NULL == mdestinationSubscriberNumber)
		throw("Object destinationSubscriberNumber is NULL");
	else
		return mdestinationSubscriberNumber;
}

capstd::capstd::OctetString* InitialDPSMSArg::getcallingPartyNumber()  { // //{//throw(const char*)
	if(NULL == mcallingPartyNumber)
		throw("Object callingPartyNumber is NULL");
	else
		return mcallingPartyNumber;
}

EventTypeSMS* InitialDPSMSArg::geteventTypeSMS()  { // //{//throw(const char*)
	if(NULL == meventTypeSMS)
		throw("Object eventTypeSMS is NULL");
	else
		return meventTypeSMS;
}

capstd::capstd::IMSI* InitialDPSMSArg::getiMSI()  { // //{//throw(const char*)
	if(NULL == miMSI)
		throw("Object iMSI is NULL");
	else
		return miMSI;
}

LocationInformation* InitialDPSMSArg::getlocationInformationMSC()  { // //{//throw(const char*)
	if(NULL == mlocationInformationMSC)
		throw("Object locationInformationMSC is NULL");
	else
		return mlocationInformationMSC;
}

LocationInformationGPRS* InitialDPSMSArg::getlocationInformationGPRS()  { // //{//throw(const char*)
	if(NULL == mlocationInformationGPRS)
		throw("Object locationInformationGPRS is NULL");
	else
		return mlocationInformationGPRS;
}

capstd::capstd::OctetString* InitialDPSMSArg::getsMSCAddress()  { // //{//throw(const char*)
	if(NULL == msMSCAddress)
		throw("Object sMSCAddress is NULL");
	else
		return msMSCAddress;
}

capstd::capstd::TimeAndTimezone* InitialDPSMSArg::gettimeAndTimezone()  { // //{//throw(const char*)
	if(NULL == mtimeAndTimezone)
		throw("Object timeAndTimezone is NULL");
	else
		return mtimeAndTimezone;
}

capstd::capstd::OctetString* InitialDPSMSArg::gettPShortMessageSpecificInfo()  { // //{//throw(const char*)
	if(NULL == mtPShortMessageSpecificInfo)
		throw("Object tPShortMessageSpecificInfo is NULL");
	else
		return mtPShortMessageSpecificInfo;
}

capstd::capstd::OctetString* InitialDPSMSArg::gettPProtocolIdentifier()  { // //{//throw(const char*)
	if(NULL == mtPProtocolIdentifier)
		throw("Object tPProtocolIdentifier is NULL");
	else
		return mtPProtocolIdentifier;
}

capstd::capstd::OctetString* InitialDPSMSArg::gettPDataCodingScheme()  { // //{//throw(const char*)
	if(NULL == mtPDataCodingScheme)
		throw("Object tPDataCodingScheme is NULL");
	else
		return mtPDataCodingScheme;
}

capstd::capstd::OctetString* InitialDPSMSArg::gettPValidityPeriod()  { // //{//throw(const char*)
	if(NULL == mtPValidityPeriod)
		throw("Object tPValidityPeriod is NULL");
	else
		return mtPValidityPeriod;
}

Extensions* InitialDPSMSArg::getextensions()  { // //{//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

capstd::capstd::CallReferenceNumber* InitialDPSMSArg::getsmsReferenceNumber()  { // //{//throw(const char*)
	if(NULL == msmsReferenceNumber)
		throw("Object smsReferenceNumber is NULL");
	else
		return msmsReferenceNumber;
}

capstd::capstd::OctetString* InitialDPSMSArg::getmscAddress()  { // //{//throw(const char*)
	if(NULL == mmscAddress)
		throw("Object mscAddress is NULL");
	else
		return mmscAddress;
}

capstd::capstd::OctetString* InitialDPSMSArg::getsgsn_Number()  { // //{//throw(const char*)
	if(NULL == msgsn_Number)
		throw("Object sgsn_Number is NULL");
	else
		return msgsn_Number;
}

capstd::capstd::OctetString* InitialDPSMSArg::getms_Classmark2()  { // //{//throw(const char*)
	if(NULL == mms_Classmark2)
		throw("Object ms_Classmark2 is NULL");
	else
		return mms_Classmark2;
}

GPRSMSClass* InitialDPSMSArg::getgPRSMSClass()  { // //{//throw(const char*)
	if(NULL == mgPRSMSClass)
		throw("Object gPRSMSClass is NULL");
	else
		return mgPRSMSClass;
}

capstd::capstd::OctetString* InitialDPSMSArg::getiMEI()  { // //{//throw(const char*)
	if(NULL == miMEI)
		throw("Object iMEI is NULL");
	else
		return miMEI;
}

capstd::capstd::OctetString* InitialDPSMSArg::getcalledPartyNumber()  { // //{//throw(const char*)
	if(NULL == mcalledPartyNumber)
		throw("Object calledPartyNumber is NULL");
	else
		return mcalledPartyNumber;
}

bool InitialDPSMSArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int InitialDPSMSArg::Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0, lengthSize = 0;
	unsigned bytesDecoded = 0;

	unsigned tag = 0;
	asn1_tag_get(array, &tag);
	(*bytesParsed) = 0;

	//This is for the sequence of choice datatype with no tag given to choice datatype
	if(lengthDecode)
	{
		lengthSize = asn1_length_decode(array, &definite, &length);


		if(-1 == lengthSize)
			return -1;
		if(!definite)
		{
			length = 1;
		}
	}

	else
		length = 1;
	while(length && decode)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0080:
				if(NULL == this->setserviceKey())
					return -1;
				if(mserviceKey->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setdestinationSubscriberNumber())
					return -1;
				if(mdestinationSubscriberNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setcallingPartyNumber())
					return -1;
				if(mcallingPartyNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->seteventTypeSMS())
					return -1;
				if(meventTypeSMS->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setiMSI())
					return -1;
				if(miMSI->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A5:
				if(NULL == this->setlocationInformationMSC())
					return -1;
				if(mlocationInformationMSC->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A6:
				if(NULL == this->setlocationInformationGPRS())
					return -1;
				if(mlocationInformationGPRS->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->setsMSCAddress())
					return -1;
				if(msMSCAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0088:
				if(NULL == this->settimeAndTimezone())
					return -1;
				if(mtimeAndTimezone->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0089:
				if(NULL == this->settPShortMessageSpecificInfo())
					return -1;
				if(mtPShortMessageSpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008A:
				if(NULL == this->settPProtocolIdentifier())
					return -1;
				if(mtPProtocolIdentifier->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008B:
				if(NULL == this->settPDataCodingScheme())
					return -1;
				if(mtPDataCodingScheme->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008C:
				if(NULL == this->settPValidityPeriod())
					return -1;
				if(mtPValidityPeriod->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AD:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008E:
				if(NULL == this->setsmsReferenceNumber())
					return -1;
				if(msmsReferenceNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008F:
				if(NULL == this->setmscAddress())
					return -1;
				if(mmscAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0090:
				if(NULL == this->setsgsn_Number())
					return -1;
				if(msgsn_Number->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0091:
				if(NULL == this->setms_Classmark2())
					return -1;
				if(mms_Classmark2->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00B2:
				if(NULL == this->setgPRSMSClass())
					return -1;
				if(mgPRSMSClass->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0093:
				if(NULL == this->setiMEI())
					return -1;
				if(miMEI->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0094:
				if(NULL == this->setcalledPartyNumber())
					return -1;
				if(mcalledPartyNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: InitialDPSMSArg Tag:%d Offset:%d\n", tag, array->offset);
				if(asn1_skip_unknown(array, &bytesDecoded) < 0)
					return -1;
		}
		if(!definite)
		{
			if((array->byte[array->offset] == 0x00 && array->byte[array->offset + 1] == 0x00) || !decode)
			{
				length += bytesDecoded + tagSize;
				array->offset += 2;
				(*bytesParsed) += length - 1 + 2;
				break;
			}
			if(array->size < array->offset)
			{
				length += bytesDecoded + tagSize;
				(*bytesParsed) += length - 1 + 2;
				printf("not found eoc size %d offset %d", array->size, array->offset);
				return -1;
			}
			(*bytesParsed) += bytesDecoded + tagSize;
		}
		else
		{
			(*bytesParsed) += bytesDecoded + tagSize;
			length -= bytesDecoded + tagSize;
			if(length < 0 || (array->size < array->offset))
				return -1;
		}
	}
	(*bytesParsed) += lengthSize;
	if(!decode)
		return -1;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("InitialDPSMSArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int InitialDPSMSArg::Encode(capstd::capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("InitialDPSMSArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	if(asn1_tag_encode(mTag, array) < 0)
		return -1;

	lLengthOffset = array->offset++;
	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case InitialDPSMSArg_SERVICEKEY:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceKey->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_DESTINATIONSUBSCRIBERNUMBER:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mdestinationSubscriberNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_CALLINGPARTYNUMBER:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingPartyNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_EVENTTYPESMS:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((meventTypeSMS->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_IMSI:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((miMSI->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_LOCATIONINFORMATIONMSC:
				if(asn1_tag_encode(165, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationInformationMSC->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_LOCATIONINFORMATIONGPRS:
				if(asn1_tag_encode(166, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationInformationGPRS->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_SMSCADDRESS:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msMSCAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_TIMEANDTIMEZONE:
				if(asn1_tag_encode(136, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeAndTimezone->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_TPSHORTMESSAGESPECIFICINFO:
				if(asn1_tag_encode(137, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtPShortMessageSpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_TPPROTOCOLIDENTIFIER:
				if(asn1_tag_encode(138, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtPProtocolIdentifier->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_TPDATACODINGSCHEME:
				if(asn1_tag_encode(139, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtPDataCodingScheme->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_TPVALIDITYPERIOD:
				if(asn1_tag_encode(140, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtPValidityPeriod->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_EXTENSIONS:
				if(asn1_tag_encode(173, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_SMSREFERENCENUMBER:
				if(asn1_tag_encode(142, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msmsReferenceNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_MSCADDRESS:
				if(asn1_tag_encode(143, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmscAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_SGSN_NUMBER:
				if(asn1_tag_encode(144, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msgsn_Number->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_MS_CLASSMARK2:
				if(asn1_tag_encode(145, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mms_Classmark2->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_GPRSMSCLASS:
				if(asn1_tag_encode(178, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgPRSMSClass->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_IMEI:
				if(asn1_tag_encode(147, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((miMEI->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPSMSArg_CALLEDPARTYNUMBER:
				if(asn1_tag_encode(148, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcalledPartyNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
				//return -1;
				break;
		}
		tagsPresent = tagsPresent & ~(lSwitchTemp);
		lTemp = ffs((int)tagsPresent);
		lSwitchTemp = (1U << (lTemp - 1));
	}
	if(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0)
		return -1;

	return 0;
}

int InitialDPSMSArg::Display(int tab){
	unsigned lTemp = 0;
	char temp[30];
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));
	sprintf(temp, "%%%ds %%s\n", tab * 3);

	while(lTemp)
	{
		switch(lSwitchTemp)
		{
			case InitialDPSMSArg_SERVICEKEY:
			{
				printf(temp, " ", "serviceKey");
				if(mserviceKey->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_DESTINATIONSUBSCRIBERNUMBER:
			{
				printf(temp, " ", "destinationSubscriberNumber");
				if(mdestinationSubscriberNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_CALLINGPARTYNUMBER:
			{
				printf(temp, " ", "callingPartyNumber");
				if(mcallingPartyNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_EVENTTYPESMS:
			{
				printf(temp, " ", "eventTypeSMS");
				if(meventTypeSMS->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_IMSI:
			{
				printf(temp, " ", "iMSI");
				if(miMSI->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_LOCATIONINFORMATIONMSC:
			{
				printf(temp, " ", "locationInformationMSC");
				if(mlocationInformationMSC->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_LOCATIONINFORMATIONGPRS:
			{
				printf(temp, " ", "locationInformationGPRS");
				if(mlocationInformationGPRS->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_SMSCADDRESS:
			{
				printf(temp, " ", "sMSCAddress");
				if(msMSCAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_TIMEANDTIMEZONE:
			{
				printf(temp, " ", "timeAndTimezone");
				if(mtimeAndTimezone->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_TPSHORTMESSAGESPECIFICINFO:
			{
				printf(temp, " ", "tPShortMessageSpecificInfo");
				if(mtPShortMessageSpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_TPPROTOCOLIDENTIFIER:
			{
				printf(temp, " ", "tPProtocolIdentifier");
				if(mtPProtocolIdentifier->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_TPDATACODINGSCHEME:
			{
				printf(temp, " ", "tPDataCodingScheme");
				if(mtPDataCodingScheme->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_TPVALIDITYPERIOD:
			{
				printf(temp, " ", "tPValidityPeriod");
				if(mtPValidityPeriod->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_SMSREFERENCENUMBER:
			{
				printf(temp, " ", "smsReferenceNumber");
				if(msmsReferenceNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_MSCADDRESS:
			{
				printf(temp, " ", "mscAddress");
				if(mmscAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_SGSN_NUMBER:
			{
				printf(temp, " ", "sgsn_Number");
				if(msgsn_Number->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_MS_CLASSMARK2:
			{
				printf(temp, " ", "ms_Classmark2");
				if(mms_Classmark2->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_GPRSMSCLASS:
			{
				printf(temp, " ", "gPRSMSClass");
				if(mgPRSMSClass->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_IMEI:
			{
				printf(temp, " ", "iMEI");
				if(miMEI->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPSMSArg_CALLEDPARTYNUMBER:
			{
				printf(temp, " ", "calledPartyNumber");
				if(mcalledPartyNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
				//return -1;
				break;
		}
		tagsPresent = tagsPresent & ~(lSwitchTemp);
		lTemp = ffs((int)tagsPresent);
		lSwitchTemp = (1U << (lTemp - 1));
	}
	return 1;
}

bool InitialDPSMSArg::ValidateMandatory(char *errStr){
	if(NULL == mserviceKey)
	{
		strcpy(errStr, "serviceKey");
		return false;
	}

	return true;
}
