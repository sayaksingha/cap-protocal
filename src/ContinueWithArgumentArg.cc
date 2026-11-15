#include "ContinueWithArgumentArg.h"

using namespace capphase3;

ContinueWithArgumentArg::ContinueWithArgumentArg()
{
	malertingPattern = NULL;
	mextensions = NULL;
	mserviceInteractionIndicatorsTwo = NULL;
	mcallingPartysCategory = NULL;
	mgenericNumbers = NULL;
	mcug_Interlock = NULL;
	mcug_OutgoingAccess = false;
	mchargeNumber = NULL;
	mcarrier = NULL;
	msuppressionOfAnnouncement = false;
	mnaOliInfo = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0081, 0X00A6, 0X00A7, 0X008C, 0X00B0, 0X0091, 0X0092, 0X9F32, 0X9F34, 0X9F37, 0X9F38};
	mTagOptional = {true, true, true, true, true, true, true, true, true, true, true};
}

ContinueWithArgumentArg::~ContinueWithArgumentArg()
{
	if(malertingPattern != NULL)
		delete malertingPattern;
	if(mextensions != NULL)
		delete mextensions;
	if(mserviceInteractionIndicatorsTwo != NULL)
		delete mserviceInteractionIndicatorsTwo;
	if(mcallingPartysCategory != NULL)
		delete mcallingPartysCategory;
	if(mgenericNumbers != NULL)
		delete mgenericNumbers;
	if(mcug_Interlock != NULL)
		delete mcug_Interlock;
	if(mchargeNumber != NULL)
		delete mchargeNumber;
	if(mcarrier != NULL)
		delete mcarrier;
	if(mnaOliInfo != NULL)
		delete mnaOliInfo;
}

capstd::OctetString* ContinueWithArgumentArg::setalertingPattern(){
	if(malertingPattern == NULL)
	{
		malertingPattern = new capstd::OctetString(3, 3);
		mTagsPresent |= ContinueWithArgumentArg_ALERTINGPATTERN;
		return malertingPattern;
	}
	else
		return malertingPattern;

}

bool ContinueWithArgumentArg::setalertingPattern(capstd::OctetString* alertingPattern){
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

Extensions* ContinueWithArgumentArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= ContinueWithArgumentArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool ContinueWithArgumentArg::setextensions(Extensions* extensions){
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

ServiceInteractionIndicatorsTwo* ContinueWithArgumentArg::setserviceInteractionIndicatorsTwo(){
	if(mserviceInteractionIndicatorsTwo == NULL)
	{
		mserviceInteractionIndicatorsTwo = new ServiceInteractionIndicatorsTwo();
		mTagsPresent |= ContinueWithArgumentArg_SERVICEINTERACTIONINDICATORSTWO;
		return mserviceInteractionIndicatorsTwo;
	}
	else
		return mserviceInteractionIndicatorsTwo;

}

bool ContinueWithArgumentArg::setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo){
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

capstd::OctetString* ContinueWithArgumentArg::setcallingPartysCategory(){
	if(mcallingPartysCategory == NULL)
	{
		mcallingPartysCategory = new capstd::OctetString(1, 1);
		mTagsPresent |= ContinueWithArgumentArg_CALLINGPARTYSCATEGORY;
		return mcallingPartysCategory;
	}
	else
		return mcallingPartysCategory;

}

bool ContinueWithArgumentArg::setcallingPartysCategory(capstd::OctetString* callingPartysCategory){
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

GenericNumbers* ContinueWithArgumentArg::setgenericNumbers(){
	if(mgenericNumbers == NULL)
	{
		mgenericNumbers = new GenericNumbers();
		mTagsPresent |= ContinueWithArgumentArg_GENERICNUMBERS;
		return mgenericNumbers;
	}
	else
		return mgenericNumbers;

}

bool ContinueWithArgumentArg::setgenericNumbers(GenericNumbers* genericNumbers){
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

capstd::OctetString* ContinueWithArgumentArg::setcug_Interlock(){
	if(mcug_Interlock == NULL)
	{
		mcug_Interlock = new capstd::OctetString(4, 4);
		mTagsPresent |= ContinueWithArgumentArg_CUG_INTERLOCK;
		return mcug_Interlock;
	}
	else
		return mcug_Interlock;

}

bool ContinueWithArgumentArg::setcug_Interlock(capstd::OctetString* cug_Interlock){
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

bool* ContinueWithArgumentArg::setcug_OutgoingAccess(){
	mcug_OutgoingAccess = true;
	mTagsPresent |= ContinueWithArgumentArg_CUG_OUTGOINGACCESS;
	mNullcug_OutgoingAccess = true;
	return &mNullcug_OutgoingAccess;
}

bool ContinueWithArgumentArg::setcug_OutgoingAccess(bool cug_OutgoingAccess){
	mcug_OutgoingAccess = cug_OutgoingAccess;
	return true;
}

capstd::OctetString* ContinueWithArgumentArg::setchargeNumber(){
	if(mchargeNumber == NULL)
	{
		mchargeNumber = new capstd::OctetString(2, 10);
		mTagsPresent |= ContinueWithArgumentArg_CHARGENUMBER;
		return mchargeNumber;
	}
	else
		return mchargeNumber;

}

bool ContinueWithArgumentArg::setchargeNumber(capstd::OctetString* chargeNumber){
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

capstd::OctetString* ContinueWithArgumentArg::setcarrier(){
	if(mcarrier == NULL)
	{
		mcarrier = new capstd::OctetString(4, 4);
		mTagsPresent |= ContinueWithArgumentArg_CARRIER;
		return mcarrier;
	}
	else
		return mcarrier;

}

bool ContinueWithArgumentArg::setcarrier(capstd::OctetString* carrier){
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

bool* ContinueWithArgumentArg::setsuppressionOfAnnouncement(){
	msuppressionOfAnnouncement = true;
	mTagsPresent |= ContinueWithArgumentArg_SUPPRESSIONOFANNOUNCEMENT;
	mNullsuppressionOfAnnouncement = true;
	return &mNullsuppressionOfAnnouncement;
}

bool ContinueWithArgumentArg::setsuppressionOfAnnouncement(bool suppressionOfAnnouncement){
	msuppressionOfAnnouncement = suppressionOfAnnouncement;
	return true;
}

capstd::OctetString* ContinueWithArgumentArg::setnaOliInfo(){
	if(mnaOliInfo == NULL)
	{
		mnaOliInfo = new capstd::OctetString(1, 1);
		mTagsPresent |= ContinueWithArgumentArg_NAOLIINFO;
		return mnaOliInfo;
	}
	else
		return mnaOliInfo;

}

bool ContinueWithArgumentArg::setnaOliInfo(capstd::OctetString* naOliInfo){
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

capstd::OctetString* ContinueWithArgumentArg::getalertingPattern() {//throw(const char*)
	if(NULL == malertingPattern)
		throw("Object alertingPattern is NULL");
	else
		return malertingPattern;
}

Extensions* ContinueWithArgumentArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

ServiceInteractionIndicatorsTwo* ContinueWithArgumentArg::getserviceInteractionIndicatorsTwo() {//throw(const char*)
	if(NULL == mserviceInteractionIndicatorsTwo)
		throw("Object serviceInteractionIndicatorsTwo is NULL");
	else
		return mserviceInteractionIndicatorsTwo;
}

capstd::OctetString* ContinueWithArgumentArg::getcallingPartysCategory() {//throw(const char*)
	if(NULL == mcallingPartysCategory)
		throw("Object callingPartysCategory is NULL");
	else
		return mcallingPartysCategory;
}

GenericNumbers* ContinueWithArgumentArg::getgenericNumbers() {//throw(const char*)
	if(NULL == mgenericNumbers)
		throw("Object genericNumbers is NULL");
	else
		return mgenericNumbers;
}

capstd::OctetString* ContinueWithArgumentArg::getcug_Interlock() {//throw(const char*)
	if(NULL == mcug_Interlock)
		throw("Object cug_Interlock is NULL");
	else
		return mcug_Interlock;
}

bool ContinueWithArgumentArg::getcug_OutgoingAccess() {
	return mcug_OutgoingAccess;
}

capstd::OctetString* ContinueWithArgumentArg::getchargeNumber() {//throw(const char*)
	if(NULL == mchargeNumber)
		throw("Object chargeNumber is NULL");
	else
		return mchargeNumber;
}

capstd::OctetString* ContinueWithArgumentArg::getcarrier() {//throw(const char*)
	if(NULL == mcarrier)
		throw("Object carrier is NULL");
	else
		return mcarrier;
}

bool ContinueWithArgumentArg::getsuppressionOfAnnouncement() {
	return msuppressionOfAnnouncement;
}

capstd::OctetString* ContinueWithArgumentArg::getnaOliInfo() {//throw(const char*)
	if(NULL == mnaOliInfo)
		throw("Object naOliInfo is NULL");
	else
		return mnaOliInfo;
}

bool ContinueWithArgumentArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ContinueWithArgumentArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X0081:
				if(NULL == this->setalertingPattern())
					return -1;
				if(malertingPattern->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A6:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A7:
				if(NULL == this->setserviceInteractionIndicatorsTwo())
					return -1;
				if(mserviceInteractionIndicatorsTwo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008C:
				if(NULL == this->setcallingPartysCategory())
					return -1;
				if(mcallingPartysCategory->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00B0:
				if(NULL == this->setgenericNumbers())
					return -1;
				if(mgenericNumbers->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0091:
				if(NULL == this->setcug_Interlock())
					return -1;
				if(mcug_Interlock->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0092:
				if(NULL == this->setcug_OutgoingAccess())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F32:
				if(NULL == this->setchargeNumber())
					return -1;
				if(mchargeNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F34:
				if(NULL == this->setcarrier())
					return -1;
				if(mcarrier->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F37:
				if(NULL == this->setsuppressionOfAnnouncement())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F38:
				if(NULL == this->setnaOliInfo())
					return -1;
				if(mnaOliInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ContinueWithArgumentArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ContinueWithArgumentArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ContinueWithArgumentArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ContinueWithArgumentArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case ContinueWithArgumentArg_ALERTINGPATTERN:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((malertingPattern->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_EXTENSIONS:
				if(asn1_tag_encode(166, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_SERVICEINTERACTIONINDICATORSTWO:
				if(asn1_tag_encode(167, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceInteractionIndicatorsTwo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_CALLINGPARTYSCATEGORY:
				if(asn1_tag_encode(140, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingPartysCategory->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_GENERICNUMBERS:
				if(asn1_tag_encode(176, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgenericNumbers->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_CUG_INTERLOCK:
				if(asn1_tag_encode(145, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcug_Interlock->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_CUG_OUTGOINGACCESS:
				if(asn1_tag_encode(146, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case ContinueWithArgumentArg_CHARGENUMBER:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mchargeNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_CARRIER:
				if(asn1_tag_encode(40756, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcarrier->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ContinueWithArgumentArg_SUPPRESSIONOFANNOUNCEMENT:
				if(asn1_tag_encode(40759, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case ContinueWithArgumentArg_NAOLIINFO:
				if(asn1_tag_encode(40760, array) < 0)
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

int ContinueWithArgumentArg::Display(int tab){
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
			case ContinueWithArgumentArg_ALERTINGPATTERN:
			{
				printf(temp, " ", "alertingPattern");
				if(malertingPattern->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_SERVICEINTERACTIONINDICATORSTWO:
			{
				printf(temp, " ", "serviceInteractionIndicatorsTwo");
				if(mserviceInteractionIndicatorsTwo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_CALLINGPARTYSCATEGORY:
			{
				printf(temp, " ", "callingPartysCategory");
				if(mcallingPartysCategory->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_GENERICNUMBERS:
			{
				printf(temp, " ", "genericNumbers");
				if(mgenericNumbers->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_CUG_INTERLOCK:
			{
				printf(temp, " ", "cug_Interlock");
				if(mcug_Interlock->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_CUG_OUTGOINGACCESS:
			{
				printf(temp, " ", "cug_OutgoingAccess");
				break;
			}
			case ContinueWithArgumentArg_CHARGENUMBER:
			{
				printf(temp, " ", "chargeNumber");
				if(mchargeNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_CARRIER:
			{
				printf(temp, " ", "carrier");
				if(mcarrier->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ContinueWithArgumentArg_SUPPRESSIONOFANNOUNCEMENT:
			{
				printf(temp, " ", "suppressionOfAnnouncement");
				break;
			}
			case ContinueWithArgumentArg_NAOLIINFO:
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

bool ContinueWithArgumentArg::ValidateMandatory(char *errStr){

	return true;
}
