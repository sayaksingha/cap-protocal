#include "InitialDPArg.h"

using namespace capphase3;

InitialDPArg::InitialDPArg()
{
	mserviceKey = NULL;
	mcalledPartyNumber = NULL;
	mcallingPartyNumber = NULL;
	mcallingPartysCategory = NULL;
	mcGEncountered = NULL;
	miPSSPCapabilities = NULL;
	mlocationNumber = NULL;
	moriginalCalledPartyID = NULL;
	mextensions = NULL;
	mhighLayerCompatibility = NULL;
	madditionalCallingPartyNumber = NULL;
	mbearerCapability = NULL;
	meventTypeBCSM = NULL;
	mredirectingPartyID = NULL;
	mredirectionInformation = NULL;
	mcause = NULL;
	mserviceInteractionIndicatorsTwo = NULL;
	mcarrier = NULL;
	mcug_Index = NULL;
	mcug_Interlock = NULL;
	mcug_OutgoingAccess = false;
	miMSI = NULL;
	msubscriberState = NULL;
	mlocationInformation = NULL;
	mext_basicServiceCode = NULL;
	mcallReferenceNumber = NULL;
	mmscAddress = NULL;
	mcalledPartyBCDNumber = NULL;
	mtimeAndTimezone = NULL;
	mgsm_ForwardingPending = false;
	minitialDPArgExtension = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0082, 0X0083, 0X0085, 0X0087, 0X0088, 0X008A, 0X008C, 0X00AF, 0X0097, 0X0099, 0X00BB, 0X009C, 0X009D, 0X009E, 0X0091, 0XBF20, 0X9F25, 0X9F2D, 0X9F2E, 0X9F2F, 0X9F32, 0XBF33, 0XBF34, 0XBF35, 0X9F36, 0X9F37, 0X9F38, 0X9F39, 0X9F3A, 0XBF3B};
	mTagOptional = {false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
}

InitialDPArg::~InitialDPArg()
{
	if(mserviceKey != NULL)
		delete mserviceKey;
	if(mcalledPartyNumber != NULL)
		delete mcalledPartyNumber;
	if(mcallingPartyNumber != NULL)
		delete mcallingPartyNumber;
	if(mcallingPartysCategory != NULL)
		delete mcallingPartysCategory;
	if(mcGEncountered != NULL)
		delete mcGEncountered;
	if(miPSSPCapabilities != NULL)
		delete miPSSPCapabilities;
	if(mlocationNumber != NULL)
		delete mlocationNumber;
	if(moriginalCalledPartyID != NULL)
		delete moriginalCalledPartyID;
	if(mextensions != NULL)
		delete mextensions;
	if(mhighLayerCompatibility != NULL)
		delete mhighLayerCompatibility;
	if(madditionalCallingPartyNumber != NULL)
		delete madditionalCallingPartyNumber;
	if(mbearerCapability != NULL)
		delete mbearerCapability;
	if(meventTypeBCSM != NULL)
		delete meventTypeBCSM;
	if(mredirectingPartyID != NULL)
		delete mredirectingPartyID;
	if(mredirectionInformation != NULL)
		delete mredirectionInformation;
	if(mcause != NULL)
		delete mcause;
	if(mserviceInteractionIndicatorsTwo != NULL)
		delete mserviceInteractionIndicatorsTwo;
	if(mcarrier != NULL)
		delete mcarrier;
	if(mcug_Index != NULL)
		delete mcug_Index;
	if(mcug_Interlock != NULL)
		delete mcug_Interlock;
	if(miMSI != NULL)
		delete miMSI;
	if(msubscriberState != NULL)
		delete msubscriberState;
	if(mlocationInformation != NULL)
		delete mlocationInformation;
	if(mext_basicServiceCode != NULL)
		delete mext_basicServiceCode;
	if(mcallReferenceNumber != NULL)
		delete mcallReferenceNumber;
	if(mmscAddress != NULL)
		delete mmscAddress;
	if(mcalledPartyBCDNumber != NULL)
		delete mcalledPartyBCDNumber;
	if(mtimeAndTimezone != NULL)
		delete mtimeAndTimezone;
	if(minitialDPArgExtension != NULL)
		delete minitialDPArgExtension;
}

capstd::INTEGER* InitialDPArg::setserviceKey(){
	if(mserviceKey == NULL)
	{
		mserviceKey = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= InitialDPArg_SERVICEKEY;
		return mserviceKey;
	}
	else
		return mserviceKey;

}

bool InitialDPArg::setserviceKey(capstd::INTEGER* serviceKey){
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

capstd::OctetString* InitialDPArg::setcalledPartyNumber(){
	if(mcalledPartyNumber == NULL)
	{
		mcalledPartyNumber = new capstd::OctetString(2, 18);
		mTagsPresent |= InitialDPArg_CALLEDPARTYNUMBER;
		return mcalledPartyNumber;
	}
	else
		return mcalledPartyNumber;

}

bool InitialDPArg::setcalledPartyNumber(capstd::OctetString* calledPartyNumber){
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

capstd::OctetString* InitialDPArg::setcallingPartyNumber(){
	if(mcallingPartyNumber == NULL)
	{
		mcallingPartyNumber = new capstd::OctetString(2, 10);
		mTagsPresent |= InitialDPArg_CALLINGPARTYNUMBER;
		return mcallingPartyNumber;
	}
	else
		return mcallingPartyNumber;

}

bool InitialDPArg::setcallingPartyNumber(capstd::OctetString* callingPartyNumber){
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

capstd::OctetString* InitialDPArg::setcallingPartysCategory(){
	if(mcallingPartysCategory == NULL)
	{
		mcallingPartysCategory = new capstd::OctetString(1, 1);
		mTagsPresent |= InitialDPArg_CALLINGPARTYSCATEGORY;
		return mcallingPartysCategory;
	}
	else
		return mcallingPartysCategory;

}

bool InitialDPArg::setcallingPartysCategory(capstd::OctetString* callingPartysCategory){
	if(mcallingPartysCategory == NULL)
	{
		return -1;
	}
	else
	{
		mcallingPartysCategory = callingPartysCategory;
		return true;
	}

}

CGEncountered* InitialDPArg::setcGEncountered(){
	if(mcGEncountered == NULL)
	{
		mcGEncountered = new CGEncountered();
		mTagsPresent |= InitialDPArg_CGENCOUNTERED;
		return mcGEncountered;
	}
	else
		return mcGEncountered;

}

bool InitialDPArg::setcGEncountered(CGEncountered* cGEncountered){
	if(mcGEncountered == NULL)
	{
		return -1;
	}
	else
	{
		mcGEncountered = cGEncountered;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setiPSSPCapabilities(){
	if(miPSSPCapabilities == NULL)
	{
		miPSSPCapabilities = new capstd::OctetString(1, 4);
		mTagsPresent |= InitialDPArg_IPSSPCAPABILITIES;
		return miPSSPCapabilities;
	}
	else
		return miPSSPCapabilities;

}

bool InitialDPArg::setiPSSPCapabilities(capstd::OctetString* iPSSPCapabilities){
	if(miPSSPCapabilities == NULL)
	{
		return -1;
	}
	else
	{
		miPSSPCapabilities = iPSSPCapabilities;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setlocationNumber(){
	if(mlocationNumber == NULL)
	{
		mlocationNumber = new capstd::OctetString(2, 10);
		mTagsPresent |= InitialDPArg_LOCATIONNUMBER;
		return mlocationNumber;
	}
	else
		return mlocationNumber;

}

bool InitialDPArg::setlocationNumber(capstd::OctetString* locationNumber){
	if(mlocationNumber == NULL)
	{
		return -1;
	}
	else
	{
		mlocationNumber = locationNumber;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setoriginalCalledPartyID(){
	if(moriginalCalledPartyID == NULL)
	{
		moriginalCalledPartyID = new capstd::OctetString(2, 10);
		mTagsPresent |= InitialDPArg_ORIGINALCALLEDPARTYID;
		return moriginalCalledPartyID;
	}
	else
		return moriginalCalledPartyID;

}

bool InitialDPArg::setoriginalCalledPartyID(capstd::OctetString* originalCalledPartyID){
	if(moriginalCalledPartyID == NULL)
	{
		return -1;
	}
	else
	{
		moriginalCalledPartyID = originalCalledPartyID;
		return true;
	}

}

Extensions* InitialDPArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= InitialDPArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool InitialDPArg::setextensions(Extensions* extensions){
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

capstd::OctetString* InitialDPArg::sethighLayerCompatibility(){
	if(mhighLayerCompatibility == NULL)
	{
		mhighLayerCompatibility = new capstd::OctetString();
		mTagsPresent |= InitialDPArg_HIGHLAYERCOMPATIBILITY;
		return mhighLayerCompatibility;
	}
	else
		return mhighLayerCompatibility;

}

bool InitialDPArg::sethighLayerCompatibility(capstd::OctetString* highLayerCompatibility){
	if(mhighLayerCompatibility == NULL)
	{
		return -1;
	}
	else
	{
		mhighLayerCompatibility = highLayerCompatibility;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setadditionalCallingPartyNumber(){
	if(madditionalCallingPartyNumber == NULL)
	{
		madditionalCallingPartyNumber = new capstd::OctetString(2, 16);
		mTagsPresent |= InitialDPArg_ADDITIONALCALLINGPARTYNUMBER;
		return madditionalCallingPartyNumber;
	}
	else
		return madditionalCallingPartyNumber;

}

bool InitialDPArg::setadditionalCallingPartyNumber(capstd::OctetString* additionalCallingPartyNumber){
	if(madditionalCallingPartyNumber == NULL)
	{
		return -1;
	}
	else
	{
		madditionalCallingPartyNumber = additionalCallingPartyNumber;
		return true;
	}

}

BearerCapability* InitialDPArg::setbearerCapability(){
	if(mbearerCapability == NULL)
	{
		mbearerCapability = new BearerCapability();
		mTagsPresent |= InitialDPArg_BEARERCAPABILITY;
		return mbearerCapability;
	}
	else
		return mbearerCapability;

}

bool InitialDPArg::setbearerCapability(BearerCapability* bearerCapability){
	if(mbearerCapability == NULL)
	{
		return -1;
	}
	else
	{
		mbearerCapability = bearerCapability;
		return true;
	}

}

EventTypeBCSM* InitialDPArg::seteventTypeBCSM(){
	if(meventTypeBCSM == NULL)
	{
		meventTypeBCSM = new EventTypeBCSM();
		mTagsPresent |= InitialDPArg_EVENTTYPEBCSM;
		return meventTypeBCSM;
	}
	else
		return meventTypeBCSM;

}

bool InitialDPArg::seteventTypeBCSM(EventTypeBCSM* eventTypeBCSM){
	if(meventTypeBCSM == NULL)
	{
		return -1;
	}
	else
	{
		meventTypeBCSM = eventTypeBCSM;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setredirectingPartyID(){
	if(mredirectingPartyID == NULL)
	{
		mredirectingPartyID = new capstd::OctetString(2, 10);
		mTagsPresent |= InitialDPArg_REDIRECTINGPARTYID;
		return mredirectingPartyID;
	}
	else
		return mredirectingPartyID;

}

bool InitialDPArg::setredirectingPartyID(capstd::OctetString* redirectingPartyID){
	if(mredirectingPartyID == NULL)
	{
		return -1;
	}
	else
	{
		mredirectingPartyID = redirectingPartyID;
		return true;
	}

}

capstd::GENERIC* InitialDPArg::setredirectionInformation(){
	if(mredirectionInformation == NULL)
	{
		mredirectionInformation = new capstd::GENERIC();
		mTagsPresent |= InitialDPArg_REDIRECTIONINFORMATION;
		return mredirectionInformation;
	}
	else
		return mredirectionInformation;

}

bool InitialDPArg::setredirectionInformation(capstd::GENERIC* redirectionInformation){
	if(mredirectionInformation == NULL)
	{
		return -1;
	}
	else
	{
		mredirectionInformation = redirectionInformation;
		return true;
	}

}

capstd::GENERIC* InitialDPArg::setcause(){
	if(mcause == NULL)
	{
		mcause = new capstd::GENERIC();
		mTagsPresent |= InitialDPArg_CAUSE;
		return mcause;
	}
	else
		return mcause;

}

bool InitialDPArg::setcause(capstd::GENERIC* cause){
	if(mcause == NULL)
	{
		return -1;
	}
	else
	{
		mcause = cause;
		return true;
	}

}

ServiceInteractionIndicatorsTwo* InitialDPArg::setserviceInteractionIndicatorsTwo(){
	if(mserviceInteractionIndicatorsTwo == NULL)
	{
		mserviceInteractionIndicatorsTwo = new ServiceInteractionIndicatorsTwo();
		mTagsPresent |= InitialDPArg_SERVICEINTERACTIONINDICATORSTWO;
		return mserviceInteractionIndicatorsTwo;
	}
	else
		return mserviceInteractionIndicatorsTwo;

}

bool InitialDPArg::setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo){
	if(mserviceInteractionIndicatorsTwo == NULL)
	{
		return -1;
	}
	else
	{
		mserviceInteractionIndicatorsTwo = serviceInteractionIndicatorsTwo;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setcarrier(){
	if(mcarrier == NULL)
	{
		mcarrier = new capstd::OctetString(4, 4);
		mTagsPresent |= InitialDPArg_CARRIER;
		return mcarrier;
	}
	else
		return mcarrier;

}

bool InitialDPArg::setcarrier(capstd::OctetString* carrier){
	if(mcarrier == NULL)
	{
		return -1;
	}
	else
	{
		mcarrier = carrier;
		return true;
	}

}

capstd::INTEGER* InitialDPArg::setcug_Index(){
	if(mcug_Index == NULL)
	{
		mcug_Index = new capstd::INTEGER(0, 32767);
		mTagsPresent |= InitialDPArg_CUG_INDEX;
		return mcug_Index;
	}
	else
		return mcug_Index;

}

bool InitialDPArg::setcug_Index(capstd::INTEGER* cug_Index){
	if(mcug_Index == NULL)
	{
		return -1;
	}
	else
	{
		mcug_Index = cug_Index;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setcug_Interlock(){
	if(mcug_Interlock == NULL)
	{
		mcug_Interlock = new capstd::OctetString(4, 4);
		mTagsPresent |= InitialDPArg_CUG_INTERLOCK;
		return mcug_Interlock;
	}
	else
		return mcug_Interlock;

}

bool InitialDPArg::setcug_Interlock(capstd::OctetString* cug_Interlock){
	if(mcug_Interlock == NULL)
	{
		return -1;
	}
	else
	{
		mcug_Interlock = cug_Interlock;
		return true;
	}

}

bool* InitialDPArg::setcug_OutgoingAccess(){
	mcug_OutgoingAccess = true;
	mTagsPresent |= InitialDPArg_CUG_OUTGOINGACCESS;
	mNullcug_OutgoingAccess = true;
	return &mNullcug_OutgoingAccess;
}

bool InitialDPArg::setcug_OutgoingAccess(bool cug_OutgoingAccess){
	mcug_OutgoingAccess = cug_OutgoingAccess;
	return true;
}

capstd::IMSI* InitialDPArg::setiMSI(){
	if(miMSI == NULL)
	{
		miMSI = new capstd::IMSI();
		mTagsPresent |= InitialDPArg_IMSI;
		return miMSI;
	}
	else
		return miMSI;

}

bool InitialDPArg::setiMSI(capstd::IMSI* iMSI){
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

SubscriberState* InitialDPArg::setsubscriberState(){
	if(msubscriberState == NULL)
	{
		msubscriberState = new SubscriberState();
		mTagsPresent |= InitialDPArg_SUBSCRIBERSTATE;
		return msubscriberState;
	}
	else
		return msubscriberState;

}

bool InitialDPArg::setsubscriberState(SubscriberState* subscriberState){
	if(msubscriberState == NULL)
	{
		return -1;
	}
	else
	{
		msubscriberState = subscriberState;
		return true;
	}

}

LocationInformation* InitialDPArg::setlocationInformation(){
	if(mlocationInformation == NULL)
	{
		mlocationInformation = new LocationInformation();
		mTagsPresent |= InitialDPArg_LOCATIONINFORMATION;
		return mlocationInformation;
	}
	else
		return mlocationInformation;

}

bool InitialDPArg::setlocationInformation(LocationInformation* locationInformation){
	if(mlocationInformation == NULL)
	{
		return -1;
	}
	else
	{
		mlocationInformation = locationInformation;
		return true;
	}

}

Ext_BasicServiceCode* InitialDPArg::setext_basicServiceCode(){
	if(mext_basicServiceCode == NULL)
	{
		mext_basicServiceCode = new Ext_BasicServiceCode();
		mTagsPresent |= InitialDPArg_EXT_BASICSERVICECODE;
		return mext_basicServiceCode;
	}
	else
		return mext_basicServiceCode;

}

bool InitialDPArg::setext_basicServiceCode(Ext_BasicServiceCode* ext_basicServiceCode){
	if(mext_basicServiceCode == NULL)
	{
		return -1;
	}
	else
	{
		mext_basicServiceCode = ext_basicServiceCode;
		return true;
	}

}

capstd::CallReferenceNumber* InitialDPArg::setcallReferenceNumber(){
	if(mcallReferenceNumber == NULL)
	{
		mcallReferenceNumber = new capstd::CallReferenceNumber();
		mTagsPresent |= InitialDPArg_CALLREFERENCENUMBER;
		return mcallReferenceNumber;
	}
	else
		return mcallReferenceNumber;

}

bool InitialDPArg::setcallReferenceNumber(capstd::CallReferenceNumber* callReferenceNumber){
	if(mcallReferenceNumber == NULL)
	{
		return -1;
	}
	else
	{
		mcallReferenceNumber = callReferenceNumber;
		return true;
	}

}

capstd::OctetString* InitialDPArg::setmscAddress(){
	if(mmscAddress == NULL)
	{
		mmscAddress = new capstd::OctetString(1, 0);
		mTagsPresent |= InitialDPArg_MSCADDRESS;
		return mmscAddress;
	}
	else
		return mmscAddress;

}

bool InitialDPArg::setmscAddress(capstd::OctetString* mscAddress){
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

capstd::OctetString* InitialDPArg::setcalledPartyBCDNumber(){
	if(mcalledPartyBCDNumber == NULL)
	{
		mcalledPartyBCDNumber = new capstd::OctetString(1, 41);
		mTagsPresent |= InitialDPArg_CALLEDPARTYBCDNUMBER;
		return mcalledPartyBCDNumber;
	}
	else
		return mcalledPartyBCDNumber;

}

bool InitialDPArg::setcalledPartyBCDNumber(capstd::OctetString* calledPartyBCDNumber){
	if(mcalledPartyBCDNumber == NULL)
	{
		return -1;
	}
	else
	{
		mcalledPartyBCDNumber = calledPartyBCDNumber;
		return true;
	}

}

capstd::TimeAndTimezone* InitialDPArg::settimeAndTimezone(){
	if(mtimeAndTimezone == NULL)
	{
		mtimeAndTimezone = new capstd::TimeAndTimezone();
		mTagsPresent |= InitialDPArg_TIMEANDTIMEZONE;
		return mtimeAndTimezone;
	}
	else
		return mtimeAndTimezone;

}

bool InitialDPArg::settimeAndTimezone(capstd::TimeAndTimezone* timeAndTimezone){
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

bool* InitialDPArg::setgsm_ForwardingPending(){
	mgsm_ForwardingPending = true;
	mTagsPresent |= InitialDPArg_GSM_FORWARDINGPENDING;
	mNullgsm_ForwardingPending = true;
	return &mNullgsm_ForwardingPending;
}

bool InitialDPArg::setgsm_ForwardingPending(bool gsm_ForwardingPending){
	mgsm_ForwardingPending = gsm_ForwardingPending;
	return true;
}

InitialDPArgExtension* InitialDPArg::setinitialDPArgExtension(){
	if(minitialDPArgExtension == NULL)
	{
		minitialDPArgExtension = new InitialDPArgExtension();
		mTagsPresent |= InitialDPArg_INITIALDPARGEXTENSION;
		return minitialDPArgExtension;
	}
	else
		return minitialDPArgExtension;

}

bool InitialDPArg::setinitialDPArgExtension(InitialDPArgExtension* initialDPArgExtension){
	if(minitialDPArgExtension == NULL)
	{
		return -1;
	}
	else
	{
		minitialDPArgExtension = initialDPArgExtension;
		return true;
	}

}

capstd::INTEGER* InitialDPArg::getserviceKey() {//throw(const char*)
	if(NULL == mserviceKey)
		throw("Object serviceKey is NULL");
	else
		return mserviceKey;
}

capstd::OctetString* InitialDPArg::getcalledPartyNumber() {//throw(const char*)
	if(NULL == mcalledPartyNumber)
		throw("Object calledPartyNumber is NULL");
	else
		return mcalledPartyNumber;
}

capstd::OctetString* InitialDPArg::getcallingPartyNumber() {//throw(const char*)
	if(NULL == mcallingPartyNumber)
		throw("Object callingPartyNumber is NULL");
	else
		return mcallingPartyNumber;
}

capstd::OctetString* InitialDPArg::getcallingPartysCategory() {//throw(const char*)
	if(NULL == mcallingPartysCategory)
		throw("Object callingPartysCategory is NULL");
	else
		return mcallingPartysCategory;
}

CGEncountered* InitialDPArg::getcGEncountered() {//throw(const char*)
	if(NULL == mcGEncountered)
		throw("Object cGEncountered is NULL");
	else
		return mcGEncountered;
}

capstd::OctetString* InitialDPArg::getiPSSPCapabilities() {//throw(const char*)
	if(NULL == miPSSPCapabilities)
		throw("Object iPSSPCapabilities is NULL");
	else
		return miPSSPCapabilities;
}

capstd::OctetString* InitialDPArg::getlocationNumber() {//throw(const char*)
	if(NULL == mlocationNumber)
		throw("Object locationNumber is NULL");
	else
		return mlocationNumber;
}

capstd::OctetString* InitialDPArg::getoriginalCalledPartyID() {//throw(const char*)
	if(NULL == moriginalCalledPartyID)
		throw("Object originalCalledPartyID is NULL");
	else
		return moriginalCalledPartyID;
}

Extensions* InitialDPArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

capstd::OctetString* InitialDPArg::gethighLayerCompatibility() {//throw(const char*)
	if(NULL == mhighLayerCompatibility)
		throw("Object highLayerCompatibility is NULL");
	else
		return mhighLayerCompatibility;
}

capstd::OctetString* InitialDPArg::getadditionalCallingPartyNumber() {//throw(const char*)
	if(NULL == madditionalCallingPartyNumber)
		throw("Object additionalCallingPartyNumber is NULL");
	else
		return madditionalCallingPartyNumber;
}

BearerCapability* InitialDPArg::getbearerCapability() {//throw(const char*)
	if(NULL == mbearerCapability)
		throw("Object bearerCapability is NULL");
	else
		return mbearerCapability;
}

EventTypeBCSM* InitialDPArg::geteventTypeBCSM() {//throw(const char*)
	if(NULL == meventTypeBCSM)
		throw("Object eventTypeBCSM is NULL");
	else
		return meventTypeBCSM;
}

capstd::OctetString* InitialDPArg::getredirectingPartyID() {//throw(const char*)
	if(NULL == mredirectingPartyID)
		throw("Object redirectingPartyID is NULL");
	else
		return mredirectingPartyID;
}

capstd::GENERIC* InitialDPArg::getredirectionInformation() {//throw(const char*)
	if(NULL == mredirectionInformation)
		throw("Object redirectionInformation is NULL");
	else
		return mredirectionInformation;
}

capstd::GENERIC* InitialDPArg::getcause() {//throw(const char*)
	if(NULL == mcause)
		throw("Object cause is NULL");
	else
		return mcause;
}

ServiceInteractionIndicatorsTwo* InitialDPArg::getserviceInteractionIndicatorsTwo() {//throw(const char*)
	if(NULL == mserviceInteractionIndicatorsTwo)
		throw("Object serviceInteractionIndicatorsTwo is NULL");
	else
		return mserviceInteractionIndicatorsTwo;
}

capstd::OctetString* InitialDPArg::getcarrier() {//throw(const char*)
	if(NULL == mcarrier)
		throw("Object carrier is NULL");
	else
		return mcarrier;
}

capstd::INTEGER* InitialDPArg::getcug_Index() {//throw(const char*)
	if(NULL == mcug_Index)
		throw("Object cug_Index is NULL");
	else
		return mcug_Index;
}

capstd::OctetString* InitialDPArg::getcug_Interlock() {//throw(const char*)
	if(NULL == mcug_Interlock)
		throw("Object cug_Interlock is NULL");
	else
		return mcug_Interlock;
}

bool InitialDPArg::getcug_OutgoingAccess() {
	return mcug_OutgoingAccess;
}

capstd::IMSI* InitialDPArg::getiMSI() {//throw(const char*)
	if(NULL == miMSI)
		throw("Object iMSI is NULL");
	else
		return miMSI;
}

SubscriberState* InitialDPArg::getsubscriberState() {//throw(const char*)
	if(NULL == msubscriberState)
		throw("Object subscriberState is NULL");
	else
		return msubscriberState;
}

LocationInformation* InitialDPArg::getlocationInformation() {//throw(const char*)
	if(NULL == mlocationInformation)
		throw("Object locationInformation is NULL");
	else
		return mlocationInformation;
}

Ext_BasicServiceCode* InitialDPArg::getext_basicServiceCode() {//throw(const char*)
	if(NULL == mext_basicServiceCode)
		throw("Object ext_basicServiceCode is NULL");
	else
		return mext_basicServiceCode;
}

capstd::CallReferenceNumber* InitialDPArg::getcallReferenceNumber() {//throw(const char*)
	if(NULL == mcallReferenceNumber)
		throw("Object callReferenceNumber is NULL");
	else
		return mcallReferenceNumber;
}

capstd::OctetString* InitialDPArg::getmscAddress() {//throw(const char*)
	if(NULL == mmscAddress)
		throw("Object mscAddress is NULL");
	else
		return mmscAddress;
}

capstd::OctetString* InitialDPArg::getcalledPartyBCDNumber() {//throw(const char*)
	if(NULL == mcalledPartyBCDNumber)
		throw("Object calledPartyBCDNumber is NULL");
	else
		return mcalledPartyBCDNumber;
}

capstd::TimeAndTimezone* InitialDPArg::gettimeAndTimezone() {//throw(const char*)
	if(NULL == mtimeAndTimezone)
		throw("Object timeAndTimezone is NULL");
	else
		return mtimeAndTimezone;
}

bool InitialDPArg::getgsm_ForwardingPending() {
	return mgsm_ForwardingPending;
}

InitialDPArgExtension* InitialDPArg::getinitialDPArgExtension() {//throw(const char*)
	if(NULL == minitialDPArgExtension)
		throw("Object initialDPArgExtension is NULL");
	else
		return minitialDPArgExtension;
}

bool InitialDPArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int InitialDPArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
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
			case 0X0082:
				if(NULL == this->setcalledPartyNumber())
					return -1;
				if(mcalledPartyNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setcallingPartyNumber())
					return -1;
				if(mcallingPartyNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setcallingPartysCategory())
					return -1;
				if(mcallingPartysCategory->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->setcGEncountered())
					return -1;
				if(mcGEncountered->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0088:
				if(NULL == this->setiPSSPCapabilities())
					return -1;
				if(miPSSPCapabilities->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008A:
				if(NULL == this->setlocationNumber())
					return -1;
				if(mlocationNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008C:
				if(NULL == this->setoriginalCalledPartyID())
					return -1;
				if(moriginalCalledPartyID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AF:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0097:
				if(NULL == this->sethighLayerCompatibility())
					return -1;
				if(mhighLayerCompatibility->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0099:
				if(NULL == this->setadditionalCallingPartyNumber())
					return -1;
				if(madditionalCallingPartyNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00BB:
				if(NULL == this->setbearerCapability())
					return -1;
				if(mbearerCapability->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009C:
				if(NULL == this->seteventTypeBCSM())
					return -1;
				if(meventTypeBCSM->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009D:
				if(NULL == this->setredirectingPartyID())
					return -1;
				if(mredirectingPartyID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009E:
				if(NULL == this->setredirectionInformation())
					return -1;
				if(mredirectionInformation->Decode(array, &bytesDecoded, mTagArray, InitialDPArg_REDIRECTIONINFORMATION) < 0)
					decode = false;
				break;
			case 0X0091:
				if(NULL == this->setcause())
					return -1;
				if(mcause->Decode(array, &bytesDecoded, mTagArray, InitialDPArg_CAUSE) < 0)
					decode = false;
				break;
			case 0XBF20:
				if(NULL == this->setserviceInteractionIndicatorsTwo())
					return -1;
				if(mserviceInteractionIndicatorsTwo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F25:
				if(NULL == this->setcarrier())
					return -1;
				if(mcarrier->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F2D:
				if(NULL == this->setcug_Index())
					return -1;
				if(mcug_Index->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F2E:
				if(NULL == this->setcug_Interlock())
					return -1;
				if(mcug_Interlock->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F2F:
				if(NULL == this->setcug_OutgoingAccess())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F32:
				if(NULL == this->setiMSI())
					return -1;
				if(miMSI->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0XBF33:
				if(NULL == this->setsubscriberState())
					return -1;
				if(msubscriberState->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0XBF34:
				if(NULL == this->setlocationInformation())
					return -1;
				if(mlocationInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0XBF35:
				if(NULL == this->setext_basicServiceCode())
					return -1;
				if(mext_basicServiceCode->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F36:
				if(NULL == this->setcallReferenceNumber())
					return -1;
				if(mcallReferenceNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F37:
				if(NULL == this->setmscAddress())
					return -1;
				if(mmscAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F38:
				if(NULL == this->setcalledPartyBCDNumber())
					return -1;
				if(mcalledPartyBCDNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F39:
				if(NULL == this->settimeAndTimezone())
					return -1;
				if(mtimeAndTimezone->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F3A:
				if(NULL == this->setgsm_ForwardingPending())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0XBF3B:
				if(NULL == this->setinitialDPArgExtension())
					return -1;
				if(minitialDPArgExtension->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: InitialDPArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("InitialDPArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int InitialDPArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("InitialDPArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case InitialDPArg_SERVICEKEY:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceKey->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CALLEDPARTYNUMBER:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcalledPartyNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CALLINGPARTYNUMBER:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingPartyNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CALLINGPARTYSCATEGORY:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingPartysCategory->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CGENCOUNTERED:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcGEncountered->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_IPSSPCAPABILITIES:
				if(asn1_tag_encode(136, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((miPSSPCapabilities->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_LOCATIONNUMBER:
				if(asn1_tag_encode(138, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_ORIGINALCALLEDPARTYID:
				if(asn1_tag_encode(140, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((moriginalCalledPartyID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_EXTENSIONS:
				if(asn1_tag_encode(175, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_HIGHLAYERCOMPATIBILITY:
				if(asn1_tag_encode(151, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mhighLayerCompatibility->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_ADDITIONALCALLINGPARTYNUMBER:
				if(asn1_tag_encode(153, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((madditionalCallingPartyNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_BEARERCAPABILITY:
				if(asn1_tag_encode(187, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbearerCapability->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_EVENTTYPEBCSM:
				if(asn1_tag_encode(156, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((meventTypeBCSM->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_REDIRECTINGPARTYID:
				if(asn1_tag_encode(157, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mredirectingPartyID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_REDIRECTIONINFORMATION:
				if(asn1_tag_encode(158, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mredirectionInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CAUSE:
				if(asn1_tag_encode(145, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcause->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_SERVICEINTERACTIONINDICATORSTWO:
				if(asn1_tag_encode(48928, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceInteractionIndicatorsTwo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CARRIER:
				if(asn1_tag_encode(40741, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcarrier->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CUG_INDEX:
				if(asn1_tag_encode(40749, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcug_Index->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CUG_INTERLOCK:
				if(asn1_tag_encode(40750, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcug_Interlock->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CUG_OUTGOINGACCESS:
				if(asn1_tag_encode(40751, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case InitialDPArg_IMSI:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((miMSI->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_SUBSCRIBERSTATE:
				if(asn1_tag_encode(48947, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msubscriberState->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_LOCATIONINFORMATION:
				if(asn1_tag_encode(48948, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_EXT_BASICSERVICECODE:
				if(asn1_tag_encode(48949, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mext_basicServiceCode->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CALLREFERENCENUMBER:
				if(asn1_tag_encode(40758, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallReferenceNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_MSCADDRESS:
				if(asn1_tag_encode(40759, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmscAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_CALLEDPARTYBCDNUMBER:
				if(asn1_tag_encode(40760, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcalledPartyBCDNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_TIMEANDTIMEZONE:
				if(asn1_tag_encode(40761, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeAndTimezone->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InitialDPArg_GSM_FORWARDINGPENDING:
				if(asn1_tag_encode(40762, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case InitialDPArg_INITIALDPARGEXTENSION:
				if(asn1_tag_encode(48955, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((minitialDPArgExtension->Encode(array) < 0) || 
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

int InitialDPArg::Display(int tab){
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
			case InitialDPArg_SERVICEKEY:
			{
				printf(temp, " ", "serviceKey");
				if(mserviceKey->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CALLEDPARTYNUMBER:
			{
				printf(temp, " ", "calledPartyNumber");
				if(mcalledPartyNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CALLINGPARTYNUMBER:
			{
				printf(temp, " ", "callingPartyNumber");
				if(mcallingPartyNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CALLINGPARTYSCATEGORY:
			{
				printf(temp, " ", "callingPartysCategory");
				if(mcallingPartysCategory->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CGENCOUNTERED:
			{
				printf(temp, " ", "cGEncountered");
				if(mcGEncountered->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_IPSSPCAPABILITIES:
			{
				printf(temp, " ", "iPSSPCapabilities");
				if(miPSSPCapabilities->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_LOCATIONNUMBER:
			{
				printf(temp, " ", "locationNumber");
				if(mlocationNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_ORIGINALCALLEDPARTYID:
			{
				printf(temp, " ", "originalCalledPartyID");
				if(moriginalCalledPartyID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_HIGHLAYERCOMPATIBILITY:
			{
				printf(temp, " ", "highLayerCompatibility");
				if(mhighLayerCompatibility->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_ADDITIONALCALLINGPARTYNUMBER:
			{
				printf(temp, " ", "additionalCallingPartyNumber");
				if(madditionalCallingPartyNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_BEARERCAPABILITY:
			{
				printf(temp, " ", "bearerCapability");
				if(mbearerCapability->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_EVENTTYPEBCSM:
			{
				printf(temp, " ", "eventTypeBCSM");
				if(meventTypeBCSM->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_REDIRECTINGPARTYID:
			{
				printf(temp, " ", "redirectingPartyID");
				if(mredirectingPartyID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_REDIRECTIONINFORMATION:
			{
				printf(temp, " ", "redirectionInformation");
				if(mredirectionInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CAUSE:
			{
				printf(temp, " ", "cause");
				if(mcause->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_SERVICEINTERACTIONINDICATORSTWO:
			{
				printf(temp, " ", "serviceInteractionIndicatorsTwo");
				if(mserviceInteractionIndicatorsTwo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CARRIER:
			{
				printf(temp, " ", "carrier");
				if(mcarrier->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CUG_INDEX:
			{
				printf(temp, " ", "cug_Index");
				if(mcug_Index->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CUG_INTERLOCK:
			{
				printf(temp, " ", "cug_Interlock");
				if(mcug_Interlock->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CUG_OUTGOINGACCESS:
			{
				printf(temp, " ", "cug_OutgoingAccess");
				break;
			}
			case InitialDPArg_IMSI:
			{
				printf(temp, " ", "iMSI");
				if(miMSI->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_SUBSCRIBERSTATE:
			{
				printf(temp, " ", "subscriberState");
				if(msubscriberState->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_LOCATIONINFORMATION:
			{
				printf(temp, " ", "locationInformation");
				if(mlocationInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_EXT_BASICSERVICECODE:
			{
				printf(temp, " ", "ext_basicServiceCode");
				if(mext_basicServiceCode->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CALLREFERENCENUMBER:
			{
				printf(temp, " ", "callReferenceNumber");
				if(mcallReferenceNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_MSCADDRESS:
			{
				printf(temp, " ", "mscAddress");
				if(mmscAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_CALLEDPARTYBCDNUMBER:
			{
				printf(temp, " ", "calledPartyBCDNumber");
				if(mcalledPartyBCDNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_TIMEANDTIMEZONE:
			{
				printf(temp, " ", "timeAndTimezone");
				if(mtimeAndTimezone->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InitialDPArg_GSM_FORWARDINGPENDING:
			{
				printf(temp, " ", "gsm_ForwardingPending");
				break;
			}
			case InitialDPArg_INITIALDPARGEXTENSION:
			{
				printf(temp, " ", "initialDPArgExtension");
				if(minitialDPArgExtension->Display(tab+1) < 0)
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

bool InitialDPArg::ValidateMandatory(char *errStr){
	if(NULL == mserviceKey)
	{
		strcpy(errStr, "serviceKey");
		return false;
	}

	return true;
}
