#include "AnyTimeInterrogationRes.h"

using namespace capphase3;

AnyTimeInterrogationRes::AnyTimeInterrogationRes()
{
	msubscriberInfo = NULL;
	mextensionContainer = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0030, 0X003F};
	mTagOptional = {false, true};
}

AnyTimeInterrogationRes::~AnyTimeInterrogationRes()
{
	if(msubscriberInfo != NULL)
		delete msubscriberInfo;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
}

SubscriberInfo* AnyTimeInterrogationRes::setsubscriberInfo(){
	if(msubscriberInfo == NULL)
	{
		msubscriberInfo = new SubscriberInfo();
		mTagsPresent |= AnyTimeInterrogationRes_SUBSCRIBERINFO;
		return msubscriberInfo;
	}
	else
		return msubscriberInfo;

}

bool AnyTimeInterrogationRes::setsubscriberInfo(SubscriberInfo* subscriberInfo){
	if(msubscriberInfo == NULL)
	{
		return -1;
	}
	else
	{
		msubscriberInfo = subscriberInfo;
		return true;
	}

}

capstd::GENERIC* AnyTimeInterrogationRes::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new capstd::GENERIC();
		mTagsPresent |= AnyTimeInterrogationRes_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool AnyTimeInterrogationRes::setextensionContainer(capstd::GENERIC* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

SubscriberInfo* AnyTimeInterrogationRes::getsubscriberInfo() {//throw(const char*)
	if(NULL == msubscriberInfo)
		throw("Object subscriberInfo is NULL");
	else
		return msubscriberInfo;
}

capstd::GENERIC* AnyTimeInterrogationRes::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

bool AnyTimeInterrogationRes::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int AnyTimeInterrogationRes::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X0030:
				if(NULL == this->setsubscriberInfo())
					return -1;
				if(msubscriberInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X003F:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded, mTagArray, AnyTimeInterrogationRes_EXTENSIONCONTAINER) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: AnyTimeInterrogationRes Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("AnyTimeInterrogationRes: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int AnyTimeInterrogationRes::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("AnyTimeInterrogationRes: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case AnyTimeInterrogationRes_SUBSCRIBERINFO:
				if(asn1_tag_encode(48, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msubscriberInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AnyTimeInterrogationRes_EXTENSIONCONTAINER:
				if(asn1_tag_encode(63, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
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

int AnyTimeInterrogationRes::Display(int tab){
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
			case AnyTimeInterrogationRes_SUBSCRIBERINFO:
			{
				printf(temp, " ", "subscriberInfo");
				if(msubscriberInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AnyTimeInterrogationRes_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
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

bool AnyTimeInterrogationRes::ValidateMandatory(char *errStr){
	if(NULL == msubscriberInfo)
	{
		strcpy(errStr, "subscriberInfo");
		return false;
	}

	return true;
}
