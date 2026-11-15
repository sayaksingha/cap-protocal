#include "ConnectToResourceArg.h"

using namespace capphase3;

ConnectToResourceArg::ConnectToResourceArg()
{
	mresourceAddress = NULL;
	mextensions = NULL;
	mserviceInteractionIndicatorsTwo = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0XFFFFFFF0, 0X00A4, 0X00A7};
	mTagOptional = {false, true, true};
}

ConnectToResourceArg::~ConnectToResourceArg()
{
	if(mresourceAddress != NULL)
		delete mresourceAddress;
	if(mextensions != NULL)
		delete mextensions;
	if(mserviceInteractionIndicatorsTwo != NULL)
		delete mserviceInteractionIndicatorsTwo;
}

ResourceAddress* ConnectToResourceArg::setresourceAddress(){
	if(mresourceAddress == NULL)
	{
		mresourceAddress = new ResourceAddress();
		mTagsPresent |= ConnectToResourceArg_RESOURCEADDRESS;
		return mresourceAddress;
	}
	else
		return mresourceAddress;

}

bool ConnectToResourceArg::setresourceAddress(ResourceAddress* resourceAddress){
	if(mresourceAddress == NULL)
	{
		return -1;
	}
	else
	{
		mresourceAddress = resourceAddress;
		return true;
	}

}

Extensions* ConnectToResourceArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= ConnectToResourceArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool ConnectToResourceArg::setextensions(Extensions* extensions){
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

ServiceInteractionIndicatorsTwo* ConnectToResourceArg::setserviceInteractionIndicatorsTwo(){
	if(mserviceInteractionIndicatorsTwo == NULL)
	{
		mserviceInteractionIndicatorsTwo = new ServiceInteractionIndicatorsTwo();
		mTagsPresent |= ConnectToResourceArg_SERVICEINTERACTIONINDICATORSTWO;
		return mserviceInteractionIndicatorsTwo;
	}
	else
		return mserviceInteractionIndicatorsTwo;

}

bool ConnectToResourceArg::setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo){
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

ResourceAddress* ConnectToResourceArg::getresourceAddress() {//throw(const char*)
	if(NULL == mresourceAddress)
		throw("Object resourceAddress is NULL");
	else
		return mresourceAddress;
}

Extensions* ConnectToResourceArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

ServiceInteractionIndicatorsTwo* ConnectToResourceArg::getserviceInteractionIndicatorsTwo() {//throw(const char*)
	if(NULL == mserviceInteractionIndicatorsTwo)
		throw("Object serviceInteractionIndicatorsTwo is NULL");
	else
		return mserviceInteractionIndicatorsTwo;
}

bool ConnectToResourceArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ConnectToResourceArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0XFFFFFFF0:
				if(NULL == this->setresourceAddress())
					return -1;
				if(mresourceAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
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
			default:
				printf("Unknown Tag received in Datatype: ConnectToResourceArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ConnectToResourceArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ConnectToResourceArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ConnectToResourceArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case ConnectToResourceArg_RESOURCEADDRESS:
				if(asn1_tag_encode(-16, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mresourceAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectToResourceArg_EXTENSIONS:
				if(asn1_tag_encode(164, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectToResourceArg_SERVICEINTERACTIONINDICATORSTWO:
				if(asn1_tag_encode(167, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceInteractionIndicatorsTwo->Encode(array) < 0) || 
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

int ConnectToResourceArg::Display(int tab){
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
			case ConnectToResourceArg_RESOURCEADDRESS:
			{
				printf(temp, " ", "resourceAddress");
				if(mresourceAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectToResourceArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectToResourceArg_SERVICEINTERACTIONINDICATORSTWO:
			{
				printf(temp, " ", "serviceInteractionIndicatorsTwo");
				if(mserviceInteractionIndicatorsTwo->Display(tab+1) < 0)
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

bool ConnectToResourceArg::ValidateMandatory(char *errStr){
	if(NULL == mresourceAddress)
	{
		strcpy(errStr, "resourceAddress");
		return false;
	}

	return true;
}
