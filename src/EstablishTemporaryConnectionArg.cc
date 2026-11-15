#include "EstablishTemporaryConnectionArg.h"

using namespace capphase3;

EstablishTemporaryConnectionArg::EstablishTemporaryConnectionArg()
{
	massistingSSPIPRoutingAddress = NULL;
	mcorrelationID = NULL;
	mscfID = NULL;
	mextensions = NULL;
	mcarrier = NULL;
	mserviceInteractionIndicatorsTwo = NULL;
	mnaOliInfo = NULL;
	mchargeNumber = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0083, 0X00A4, 0X0085, 0X00A6, 0X9F32, 0X9F33};
	mTagOptional = {false, true, true, true, true, true, true, true};
}

EstablishTemporaryConnectionArg::~EstablishTemporaryConnectionArg()
{
	if(massistingSSPIPRoutingAddress != NULL)
		delete massistingSSPIPRoutingAddress;
	if(mcorrelationID != NULL)
		delete mcorrelationID;
	if(mscfID != NULL)
		delete mscfID;
	if(mextensions != NULL)
		delete mextensions;
	if(mcarrier != NULL)
		delete mcarrier;
	if(mserviceInteractionIndicatorsTwo != NULL)
		delete mserviceInteractionIndicatorsTwo;
	if(mnaOliInfo != NULL)
		delete mnaOliInfo;
	if(mchargeNumber != NULL)
		delete mchargeNumber;
}

capstd::OctetString* EstablishTemporaryConnectionArg::setassistingSSPIPRoutingAddress(){
	if(massistingSSPIPRoutingAddress == NULL)
	{
		massistingSSPIPRoutingAddress = new capstd::OctetString(2, 16);
		mTagsPresent |= EstablishTemporaryConnectionArg_ASSISTINGSSPIPROUTINGADDRESS;
		return massistingSSPIPRoutingAddress;
	}
	else
		return massistingSSPIPRoutingAddress;

}

bool EstablishTemporaryConnectionArg::setassistingSSPIPRoutingAddress(capstd::OctetString* assistingSSPIPRoutingAddress){
	if(massistingSSPIPRoutingAddress == NULL)
	{
		return -1;
	}
	else
	{
		massistingSSPIPRoutingAddress = assistingSSPIPRoutingAddress;
		return true;
	}

}

capstd::OctetString* EstablishTemporaryConnectionArg::setcorrelationID(){
	if(mcorrelationID == NULL)
	{
		mcorrelationID = new capstd::OctetString(2, 16);
		mTagsPresent |= EstablishTemporaryConnectionArg_CORRELATIONID;
		return mcorrelationID;
	}
	else
		return mcorrelationID;

}

bool EstablishTemporaryConnectionArg::setcorrelationID(capstd::OctetString* correlationID){
	if(mcorrelationID == NULL)
	{
		return -1;
	}
	else
	{
		mcorrelationID = correlationID;
		return true;
	}

}

capstd::OctetString* EstablishTemporaryConnectionArg::setscfID(){
	if(mscfID == NULL)
	{
		mscfID = new capstd::OctetString(2, 10);
		mTagsPresent |= EstablishTemporaryConnectionArg_SCFID;
		return mscfID;
	}
	else
		return mscfID;

}

bool EstablishTemporaryConnectionArg::setscfID(capstd::OctetString* scfID){
	if(mscfID == NULL)
	{
		return -1;
	}
	else
	{
		mscfID = scfID;
		return true;
	}

}

Extensions* EstablishTemporaryConnectionArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= EstablishTemporaryConnectionArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool EstablishTemporaryConnectionArg::setextensions(Extensions* extensions){
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

capstd::OctetString* EstablishTemporaryConnectionArg::setcarrier(){
	if(mcarrier == NULL)
	{
		mcarrier = new capstd::OctetString(4, 4);
		mTagsPresent |= EstablishTemporaryConnectionArg_CARRIER;
		return mcarrier;
	}
	else
		return mcarrier;

}

bool EstablishTemporaryConnectionArg::setcarrier(capstd::OctetString* carrier){
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

ServiceInteractionIndicatorsTwo* EstablishTemporaryConnectionArg::setserviceInteractionIndicatorsTwo(){
	if(mserviceInteractionIndicatorsTwo == NULL)
	{
		mserviceInteractionIndicatorsTwo = new ServiceInteractionIndicatorsTwo();
		mTagsPresent |= EstablishTemporaryConnectionArg_SERVICEINTERACTIONINDICATORSTWO;
		return mserviceInteractionIndicatorsTwo;
	}
	else
		return mserviceInteractionIndicatorsTwo;

}

bool EstablishTemporaryConnectionArg::setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo){
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

capstd::OctetString* EstablishTemporaryConnectionArg::setnaOliInfo(){
	if(mnaOliInfo == NULL)
	{
		mnaOliInfo = new capstd::OctetString(1, 1);
		mTagsPresent |= EstablishTemporaryConnectionArg_NAOLIINFO;
		return mnaOliInfo;
	}
	else
		return mnaOliInfo;

}

bool EstablishTemporaryConnectionArg::setnaOliInfo(capstd::OctetString* naOliInfo){
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

capstd::OctetString* EstablishTemporaryConnectionArg::setchargeNumber(){
	if(mchargeNumber == NULL)
	{
		mchargeNumber = new capstd::OctetString(2, 10);
		mTagsPresent |= EstablishTemporaryConnectionArg_CHARGENUMBER;
		return mchargeNumber;
	}
	else
		return mchargeNumber;

}

bool EstablishTemporaryConnectionArg::setchargeNumber(capstd::OctetString* chargeNumber){
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

capstd::OctetString* EstablishTemporaryConnectionArg::getassistingSSPIPRoutingAddress() {//throw(const char*)
	if(NULL == massistingSSPIPRoutingAddress)
		throw("Object assistingSSPIPRoutingAddress is NULL");
	else
		return massistingSSPIPRoutingAddress;
}

capstd::OctetString* EstablishTemporaryConnectionArg::getcorrelationID() {//throw(const char*)
	if(NULL == mcorrelationID)
		throw("Object correlationID is NULL");
	else
		return mcorrelationID;
}

capstd::OctetString* EstablishTemporaryConnectionArg::getscfID() {//throw(const char*)
	if(NULL == mscfID)
		throw("Object scfID is NULL");
	else
		return mscfID;
}

Extensions* EstablishTemporaryConnectionArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

capstd::OctetString* EstablishTemporaryConnectionArg::getcarrier() {//throw(const char*)
	if(NULL == mcarrier)
		throw("Object carrier is NULL");
	else
		return mcarrier;
}

ServiceInteractionIndicatorsTwo* EstablishTemporaryConnectionArg::getserviceInteractionIndicatorsTwo() {//throw(const char*)
	if(NULL == mserviceInteractionIndicatorsTwo)
		throw("Object serviceInteractionIndicatorsTwo is NULL");
	else
		return mserviceInteractionIndicatorsTwo;
}

capstd::OctetString* EstablishTemporaryConnectionArg::getnaOliInfo() {//throw(const char*)
	if(NULL == mnaOliInfo)
		throw("Object naOliInfo is NULL");
	else
		return mnaOliInfo;
}

capstd::OctetString* EstablishTemporaryConnectionArg::getchargeNumber() {//throw(const char*)
	if(NULL == mchargeNumber)
		throw("Object chargeNumber is NULL");
	else
		return mchargeNumber;
}

bool EstablishTemporaryConnectionArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int EstablishTemporaryConnectionArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				if(NULL == this->setassistingSSPIPRoutingAddress())
					return -1;
				if(massistingSSPIPRoutingAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setcorrelationID())
					return -1;
				if(mcorrelationID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setscfID())
					return -1;
				if(mscfID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setcarrier())
					return -1;
				if(mcarrier->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A6:
				if(NULL == this->setserviceInteractionIndicatorsTwo())
					return -1;
				if(mserviceInteractionIndicatorsTwo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F32:
				if(NULL == this->setnaOliInfo())
					return -1;
				if(mnaOliInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F33:
				if(NULL == this->setchargeNumber())
					return -1;
				if(mchargeNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: EstablishTemporaryConnectionArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("EstablishTemporaryConnectionArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int EstablishTemporaryConnectionArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("EstablishTemporaryConnectionArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case EstablishTemporaryConnectionArg_ASSISTINGSSPIPROUTINGADDRESS:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((massistingSSPIPRoutingAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EstablishTemporaryConnectionArg_CORRELATIONID:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcorrelationID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EstablishTemporaryConnectionArg_SCFID:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mscfID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EstablishTemporaryConnectionArg_EXTENSIONS:
				if(asn1_tag_encode(164, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EstablishTemporaryConnectionArg_CARRIER:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcarrier->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EstablishTemporaryConnectionArg_SERVICEINTERACTIONINDICATORSTWO:
				if(asn1_tag_encode(166, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceInteractionIndicatorsTwo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EstablishTemporaryConnectionArg_NAOLIINFO:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnaOliInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EstablishTemporaryConnectionArg_CHARGENUMBER:
				if(asn1_tag_encode(40755, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mchargeNumber->Encode(array) < 0) || 
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

int EstablishTemporaryConnectionArg::Display(int tab){
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
			case EstablishTemporaryConnectionArg_ASSISTINGSSPIPROUTINGADDRESS:
			{
				printf(temp, " ", "assistingSSPIPRoutingAddress");
				if(massistingSSPIPRoutingAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EstablishTemporaryConnectionArg_CORRELATIONID:
			{
				printf(temp, " ", "correlationID");
				if(mcorrelationID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EstablishTemporaryConnectionArg_SCFID:
			{
				printf(temp, " ", "scfID");
				if(mscfID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EstablishTemporaryConnectionArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EstablishTemporaryConnectionArg_CARRIER:
			{
				printf(temp, " ", "carrier");
				if(mcarrier->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EstablishTemporaryConnectionArg_SERVICEINTERACTIONINDICATORSTWO:
			{
				printf(temp, " ", "serviceInteractionIndicatorsTwo");
				if(mserviceInteractionIndicatorsTwo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EstablishTemporaryConnectionArg_NAOLIINFO:
			{
				printf(temp, " ", "naOliInfo");
				if(mnaOliInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EstablishTemporaryConnectionArg_CHARGENUMBER:
			{
				printf(temp, " ", "chargeNumber");
				if(mchargeNumber->Display(tab+1) < 0)
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

bool EstablishTemporaryConnectionArg::ValidateMandatory(char *errStr){
	if(NULL == massistingSSPIPRoutingAddress)
	{
		strcpy(errStr, "assistingSSPIPRoutingAddress");
		return false;
	}

	return true;
}
