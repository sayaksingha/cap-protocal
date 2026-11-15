#include "ConnectArg.h"

using namespace capphase3;

ConnectArg::ConnectArg()
{
	mdestinationRoutingAddress = NULL;
	malertingPattern = NULL;
	moriginalCalledPartyID = NULL;
	mextensions = NULL;
	mcarrier = NULL;
	mcallingPartysCategory = NULL;
	mredirectingPartyID = NULL;
	mredirectionInformation = NULL;
	mgenericNumbers = NULL;
	mserviceInteractionIndicatorsTwo = NULL;
	mchargeNumber = NULL;
	mcug_Interlock = NULL;
	mcug_OutgoingAccess = false;
	msuppressionOfAnnouncement = false;
	moCSIApplicable = false;
	mnaOliInfo = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X0081, 0X0086, 0X00AA, 0X008B, 0X009C, 0X009D, 0X009E, 0X00AE, 0X00AF, 0X0093, 0X9F1F, 0X9F20, 0X9F37, 0X9F38, 0X9F39};
	mTagOptional = {false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
}

ConnectArg::~ConnectArg()
{
	if(mdestinationRoutingAddress != NULL)
		delete mdestinationRoutingAddress;
	if(malertingPattern != NULL)
		delete malertingPattern;
	if(moriginalCalledPartyID != NULL)
		delete moriginalCalledPartyID;
	if(mextensions != NULL)
		delete mextensions;
	if(mcarrier != NULL)
		delete mcarrier;
	if(mcallingPartysCategory != NULL)
		delete mcallingPartysCategory;
	if(mredirectingPartyID != NULL)
		delete mredirectingPartyID;
	if(mredirectionInformation != NULL)
		delete mredirectionInformation;
	if(mgenericNumbers != NULL)
		delete mgenericNumbers;
	if(mserviceInteractionIndicatorsTwo != NULL)
		delete mserviceInteractionIndicatorsTwo;
	if(mchargeNumber != NULL)
		delete mchargeNumber;
	if(mcug_Interlock != NULL)
		delete mcug_Interlock;
	if(mnaOliInfo != NULL)
		delete mnaOliInfo;
}

DestinationRoutingAddress* ConnectArg::setdestinationRoutingAddress(){
	if(mdestinationRoutingAddress == NULL)
	{
		mdestinationRoutingAddress = new DestinationRoutingAddress();
		mTagsPresent |= ConnectArg_DESTINATIONROUTINGADDRESS;
		return mdestinationRoutingAddress;
	}
	else
		return mdestinationRoutingAddress;

}

bool ConnectArg::setdestinationRoutingAddress(DestinationRoutingAddress* destinationRoutingAddress){
	if(mdestinationRoutingAddress == NULL)
	{
		return -1;
	}
	else
	{
		mdestinationRoutingAddress = destinationRoutingAddress;
		return true;
	}

}

capstd::OctetString* ConnectArg::setalertingPattern(){
	if(malertingPattern == NULL)
	{
		malertingPattern = new capstd::OctetString(3, 3);
		mTagsPresent |= ConnectArg_ALERTINGPATTERN;
		return malertingPattern;
	}
	else
		return malertingPattern;

}

bool ConnectArg::setalertingPattern(capstd::OctetString* alertingPattern){
	if(malertingPattern == NULL)
	{
		return -1;
	}
	else
	{
		malertingPattern = alertingPattern;
		return true;
	}

}

capstd::OctetString* ConnectArg::setoriginalCalledPartyID(){
	if(moriginalCalledPartyID == NULL)
	{
		moriginalCalledPartyID = new capstd::OctetString(2, 10);
		mTagsPresent |= ConnectArg_ORIGINALCALLEDPARTYID;
		return moriginalCalledPartyID;
	}
	else
		return moriginalCalledPartyID;

}

bool ConnectArg::setoriginalCalledPartyID(capstd::OctetString* originalCalledPartyID){
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

Extensions* ConnectArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= ConnectArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool ConnectArg::setextensions(Extensions* extensions){
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

capstd::OctetString* ConnectArg::setcarrier(){
	if(mcarrier == NULL)
	{
		mcarrier = new capstd::OctetString(4, 4);
		mTagsPresent |= ConnectArg_CARRIER;
		return mcarrier;
	}
	else
		return mcarrier;

}

bool ConnectArg::setcarrier(capstd::OctetString* carrier){
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

capstd::OctetString* ConnectArg::setcallingPartysCategory(){
	if(mcallingPartysCategory == NULL)
	{
		mcallingPartysCategory = new capstd::OctetString(1, 1);
		mTagsPresent |= ConnectArg_CALLINGPARTYSCATEGORY;
		return mcallingPartysCategory;
	}
	else
		return mcallingPartysCategory;

}

bool ConnectArg::setcallingPartysCategory(capstd::OctetString* callingPartysCategory){
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

capstd::OctetString* ConnectArg::setredirectingPartyID(){
	if(mredirectingPartyID == NULL)
	{
		mredirectingPartyID = new capstd::OctetString(2, 10);
		mTagsPresent |= ConnectArg_REDIRECTINGPARTYID;
		return mredirectingPartyID;
	}
	else
		return mredirectingPartyID;

}

bool ConnectArg::setredirectingPartyID(capstd::OctetString* redirectingPartyID){
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

capstd::GENERIC* ConnectArg::setredirectionInformation(){
	if(mredirectionInformation == NULL)
	{
		mredirectionInformation = new capstd::GENERIC();
		mTagsPresent |= ConnectArg_REDIRECTIONINFORMATION;
		return mredirectionInformation;
	}
	else
		return mredirectionInformation;

}

bool ConnectArg::setredirectionInformation(capstd::GENERIC* redirectionInformation){
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

GenericNumbers* ConnectArg::setgenericNumbers(){
	if(mgenericNumbers == NULL)
	{
		mgenericNumbers = new GenericNumbers();
		mTagsPresent |= ConnectArg_GENERICNUMBERS;
		return mgenericNumbers;
	}
	else
		return mgenericNumbers;

}

bool ConnectArg::setgenericNumbers(GenericNumbers* genericNumbers){
	if(mgenericNumbers == NULL)
	{
		return -1;
	}
	else
	{
		mgenericNumbers = genericNumbers;
		return true;
	}

}

ServiceInteractionIndicatorsTwo* ConnectArg::setserviceInteractionIndicatorsTwo(){
	if(mserviceInteractionIndicatorsTwo == NULL)
	{
		mserviceInteractionIndicatorsTwo = new ServiceInteractionIndicatorsTwo();
		mTagsPresent |= ConnectArg_SERVICEINTERACTIONINDICATORSTWO;
		return mserviceInteractionIndicatorsTwo;
	}
	else
		return mserviceInteractionIndicatorsTwo;

}

bool ConnectArg::setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo){
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

capstd::OctetString* ConnectArg::setchargeNumber(){
	if(mchargeNumber == NULL)
	{
		mchargeNumber = new capstd::OctetString(2, 10);
		mTagsPresent |= ConnectArg_CHARGENUMBER;
		return mchargeNumber;
	}
	else
		return mchargeNumber;

}

bool ConnectArg::setchargeNumber(capstd::OctetString* chargeNumber){
	if(mchargeNumber == NULL)
	{
		return -1;
	}
	else
	{
		mchargeNumber = chargeNumber;
		return true;
	}

}

capstd::OctetString* ConnectArg::setcug_Interlock(){
	if(mcug_Interlock == NULL)
	{
		mcug_Interlock = new capstd::OctetString(4, 4);
		mTagsPresent |= ConnectArg_CUG_INTERLOCK;
		return mcug_Interlock;
	}
	else
		return mcug_Interlock;

}

bool ConnectArg::setcug_Interlock(capstd::OctetString* cug_Interlock){
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

bool* ConnectArg::setcug_OutgoingAccess(){
	mcug_OutgoingAccess = true;
	mTagsPresent |= ConnectArg_CUG_OUTGOINGACCESS;
	mNullcug_OutgoingAccess = true;
	return &mNullcug_OutgoingAccess;
}

bool ConnectArg::setcug_OutgoingAccess(bool cug_OutgoingAccess){
	mcug_OutgoingAccess = cug_OutgoingAccess;
	return true;
}

bool* ConnectArg::setsuppressionOfAnnouncement(){
	msuppressionOfAnnouncement = true;
	mTagsPresent |= ConnectArg_SUPPRESSIONOFANNOUNCEMENT;
	mNullsuppressionOfAnnouncement = true;
	return &mNullsuppressionOfAnnouncement;
}

bool ConnectArg::setsuppressionOfAnnouncement(bool suppressionOfAnnouncement){
	msuppressionOfAnnouncement = suppressionOfAnnouncement;
	return true;
}

bool* ConnectArg::setoCSIApplicable(){
	moCSIApplicable = true;
	mTagsPresent |= ConnectArg_OCSIAPPLICABLE;
	mNulloCSIApplicable = true;
	return &mNulloCSIApplicable;
}

bool ConnectArg::setoCSIApplicable(bool oCSIApplicable){
	moCSIApplicable = oCSIApplicable;
	return true;
}

capstd::OctetString* ConnectArg::setnaOliInfo(){
	if(mnaOliInfo == NULL)
	{
		mnaOliInfo = new capstd::OctetString(1, 1);
		mTagsPresent |= ConnectArg_NAOLIINFO;
		return mnaOliInfo;
	}
	else
		return mnaOliInfo;

}

bool ConnectArg::setnaOliInfo(capstd::OctetString* naOliInfo){
	if(mnaOliInfo == NULL)
	{
		return -1;
	}
	else
	{
		mnaOliInfo = naOliInfo;
		return true;
	}

}

DestinationRoutingAddress* ConnectArg::getdestinationRoutingAddress() {//throw(const char*)
	if(NULL == mdestinationRoutingAddress)
		throw("Object destinationRoutingAddress is NULL");
	else
		return mdestinationRoutingAddress;
}

capstd::OctetString* ConnectArg::getalertingPattern() {//throw(const char*)
	if(NULL == malertingPattern)
		throw("Object alertingPattern is NULL");
	else
		return malertingPattern;
}

capstd::OctetString* ConnectArg::getoriginalCalledPartyID() {//throw(const char*)
	if(NULL == moriginalCalledPartyID)
		throw("Object originalCalledPartyID is NULL");
	else
		return moriginalCalledPartyID;
}

Extensions* ConnectArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

capstd::OctetString* ConnectArg::getcarrier() {//throw(const char*)
	if(NULL == mcarrier)
		throw("Object carrier is NULL");
	else
		return mcarrier;
}

capstd::OctetString* ConnectArg::getcallingPartysCategory() {//throw(const char*)
	if(NULL == mcallingPartysCategory)
		throw("Object callingPartysCategory is NULL");
	else
		return mcallingPartysCategory;
}

capstd::OctetString* ConnectArg::getredirectingPartyID() {//throw(const char*)
	if(NULL == mredirectingPartyID)
		throw("Object redirectingPartyID is NULL");
	else
		return mredirectingPartyID;
}

capstd::GENERIC* ConnectArg::getredirectionInformation() {//throw(const char*)
	if(NULL == mredirectionInformation)
		throw("Object redirectionInformation is NULL");
	else
		return mredirectionInformation;
}

GenericNumbers* ConnectArg::getgenericNumbers() {//throw(const char*)
	if(NULL == mgenericNumbers)
		throw("Object genericNumbers is NULL");
	else
		return mgenericNumbers;
}

ServiceInteractionIndicatorsTwo* ConnectArg::getserviceInteractionIndicatorsTwo() {//throw(const char*)
	if(NULL == mserviceInteractionIndicatorsTwo)
		throw("Object serviceInteractionIndicatorsTwo is NULL");
	else
		return mserviceInteractionIndicatorsTwo;
}

capstd::OctetString* ConnectArg::getchargeNumber() {//throw(const char*)
	if(NULL == mchargeNumber)
		throw("Object chargeNumber is NULL");
	else
		return mchargeNumber;
}

capstd::OctetString* ConnectArg::getcug_Interlock() {//throw(const char*)
	if(NULL == mcug_Interlock)
		throw("Object cug_Interlock is NULL");
	else
		return mcug_Interlock;
}

bool ConnectArg::getcug_OutgoingAccess() {
	return mcug_OutgoingAccess;
}

bool ConnectArg::getsuppressionOfAnnouncement() {
	return msuppressionOfAnnouncement;
}

bool ConnectArg::getoCSIApplicable() {
	return moCSIApplicable;
}

capstd::OctetString* ConnectArg::getnaOliInfo() {//throw(const char*)
	if(NULL == mnaOliInfo)
		throw("Object naOliInfo is NULL");
	else
		return mnaOliInfo;
}

bool ConnectArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ConnectArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X00A0:
				if(NULL == this->setdestinationRoutingAddress())
					return -1;
				if(mdestinationRoutingAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setalertingPattern())
					return -1;
				if(malertingPattern->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setoriginalCalledPartyID())
					return -1;
				if(moriginalCalledPartyID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AA:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008B:
				if(NULL == this->setcarrier())
					return -1;
				if(mcarrier->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009C:
				if(NULL == this->setcallingPartysCategory())
					return -1;
				if(mcallingPartysCategory->Decode(array, &bytesDecoded) < 0)
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
				if(mredirectionInformation->Decode(array, &bytesDecoded, mTagArray, ConnectArg_REDIRECTIONINFORMATION) < 0)
					decode = false;
				break;
			case 0X00AE:
				if(NULL == this->setgenericNumbers())
					return -1;
				if(mgenericNumbers->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AF:
				if(NULL == this->setserviceInteractionIndicatorsTwo())
					return -1;
				if(mserviceInteractionIndicatorsTwo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0093:
				if(NULL == this->setchargeNumber())
					return -1;
				if(mchargeNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F1F:
				if(NULL == this->setcug_Interlock())
					return -1;
				if(mcug_Interlock->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F20:
				if(NULL == this->setcug_OutgoingAccess())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F37:
				if(NULL == this->setsuppressionOfAnnouncement())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F38:
				if(NULL == this->setoCSIApplicable())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F39:
				if(NULL == this->setnaOliInfo())
					return -1;
				if(mnaOliInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ConnectArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ConnectArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ConnectArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ConnectArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case ConnectArg_DESTINATIONROUTINGADDRESS:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mdestinationRoutingAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_ALERTINGPATTERN:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((malertingPattern->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_ORIGINALCALLEDPARTYID:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((moriginalCalledPartyID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_EXTENSIONS:
				if(asn1_tag_encode(170, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_CARRIER:
				if(asn1_tag_encode(139, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcarrier->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_CALLINGPARTYSCATEGORY:
				if(asn1_tag_encode(156, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingPartysCategory->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_REDIRECTINGPARTYID:
				if(asn1_tag_encode(157, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mredirectingPartyID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_REDIRECTIONINFORMATION:
				if(asn1_tag_encode(158, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mredirectionInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_GENERICNUMBERS:
				if(asn1_tag_encode(174, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgenericNumbers->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_SERVICEINTERACTIONINDICATORSTWO:
				if(asn1_tag_encode(175, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceInteractionIndicatorsTwo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_CHARGENUMBER:
				if(asn1_tag_encode(147, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mchargeNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_CUG_INTERLOCK:
				if(asn1_tag_encode(40735, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcug_Interlock->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectArg_CUG_OUTGOINGACCESS:
				if(asn1_tag_encode(40736, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case ConnectArg_SUPPRESSIONOFANNOUNCEMENT:
				if(asn1_tag_encode(40759, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case ConnectArg_OCSIAPPLICABLE:
				if(asn1_tag_encode(40760, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case ConnectArg_NAOLIINFO:
				if(asn1_tag_encode(40761, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnaOliInfo->Encode(array) < 0) || 
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

int ConnectArg::Display(int tab){
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
			case ConnectArg_DESTINATIONROUTINGADDRESS:
			{
				printf(temp, " ", "destinationRoutingAddress");
				if(mdestinationRoutingAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_ALERTINGPATTERN:
			{
				printf(temp, " ", "alertingPattern");
				if(malertingPattern->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_ORIGINALCALLEDPARTYID:
			{
				printf(temp, " ", "originalCalledPartyID");
				if(moriginalCalledPartyID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_CARRIER:
			{
				printf(temp, " ", "carrier");
				if(mcarrier->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_CALLINGPARTYSCATEGORY:
			{
				printf(temp, " ", "callingPartysCategory");
				if(mcallingPartysCategory->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_REDIRECTINGPARTYID:
			{
				printf(temp, " ", "redirectingPartyID");
				if(mredirectingPartyID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_REDIRECTIONINFORMATION:
			{
				printf(temp, " ", "redirectionInformation");
				if(mredirectionInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_GENERICNUMBERS:
			{
				printf(temp, " ", "genericNumbers");
				if(mgenericNumbers->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_SERVICEINTERACTIONINDICATORSTWO:
			{
				printf(temp, " ", "serviceInteractionIndicatorsTwo");
				if(mserviceInteractionIndicatorsTwo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_CHARGENUMBER:
			{
				printf(temp, " ", "chargeNumber");
				if(mchargeNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_CUG_INTERLOCK:
			{
				printf(temp, " ", "cug_Interlock");
				if(mcug_Interlock->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectArg_CUG_OUTGOINGACCESS:
			{
				printf(temp, " ", "cug_OutgoingAccess");
				break;
			}
			case ConnectArg_SUPPRESSIONOFANNOUNCEMENT:
			{
				printf(temp, " ", "suppressionOfAnnouncement");
				break;
			}
			case ConnectArg_OCSIAPPLICABLE:
			{
				printf(temp, " ", "oCSIApplicable");
				break;
			}
			case ConnectArg_NAOLIINFO:
			{
				printf(temp, " ", "naOliInfo");
				if(mnaOliInfo->Display(tab+1) < 0)
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

bool ConnectArg::ValidateMandatory(char *errStr){
	if(NULL == mdestinationRoutingAddress)
	{
		strcpy(errStr, "destinationRoutingAddress");
		return false;
	}

	return true;
}
