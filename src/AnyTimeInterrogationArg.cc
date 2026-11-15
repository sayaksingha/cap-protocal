#include "AnyTimeInterrogationArg.h"

using namespace capphase3;

AnyTimeInterrogationArg::AnyTimeInterrogationArg()
{
	msubscriberIdentity = NULL;
	mrequestedInfo = NULL;
	mextensionContainer = NULL;
	mgsmSCF_Address = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A1, 0X00A2, 0X0083};
	mTagOptional = {false, false, true, false};
}

AnyTimeInterrogationArg::~AnyTimeInterrogationArg()
{
	if(msubscriberIdentity != NULL)
		delete msubscriberIdentity;
	if(mrequestedInfo != NULL)
		delete mrequestedInfo;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
	if(mgsmSCF_Address != NULL)
		delete mgsmSCF_Address;
}

SubscriberIdentity* AnyTimeInterrogationArg::setsubscriberIdentity(){
	if(msubscriberIdentity == NULL)
	{
		msubscriberIdentity = new SubscriberIdentity();
		mTagsPresent |= AnyTimeInterrogationArg_SUBSCRIBERIDENTITY;
		return msubscriberIdentity;
	}
	else
		return msubscriberIdentity;

}

bool AnyTimeInterrogationArg::setsubscriberIdentity(SubscriberIdentity* subscriberIdentity){
	if(msubscriberIdentity == NULL)
	{
		return -1;
	}
	else
	{
		msubscriberIdentity = subscriberIdentity;
		return true;
	}

}

RequestedInfo* AnyTimeInterrogationArg::setrequestedInfo(){
	if(mrequestedInfo == NULL)
	{
		mrequestedInfo = new RequestedInfo();
		mTagsPresent |= AnyTimeInterrogationArg_REQUESTEDINFO;
		return mrequestedInfo;
	}
	else
		return mrequestedInfo;

}

bool AnyTimeInterrogationArg::setrequestedInfo(RequestedInfo* requestedInfo){
	if(mrequestedInfo == NULL)
	{
		return -1;
	}
	else
	{
		mrequestedInfo = requestedInfo;
		return true;
	}

}

capstd::GENERIC* AnyTimeInterrogationArg::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new capstd::GENERIC();
		mTagsPresent |= AnyTimeInterrogationArg_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool AnyTimeInterrogationArg::setextensionContainer(capstd::GENERIC* extensionContainer){
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

capstd::OctetString* AnyTimeInterrogationArg::setgsmSCF_Address(){
	if(mgsmSCF_Address == NULL)
	{
		mgsmSCF_Address = new capstd::OctetString(1, 0);
		mTagsPresent |= AnyTimeInterrogationArg_GSMSCF_ADDRESS;
		return mgsmSCF_Address;
	}
	else
		return mgsmSCF_Address;

}

bool AnyTimeInterrogationArg::setgsmSCF_Address(capstd::OctetString* gsmSCF_Address){
	if(mgsmSCF_Address == NULL)
	{
		return -1;
	}
	else
	{
		mgsmSCF_Address = gsmSCF_Address;
		return true;
	}

}

SubscriberIdentity* AnyTimeInterrogationArg::getsubscriberIdentity() {//throw(const char*)
	if(NULL == msubscriberIdentity)
		throw("Object subscriberIdentity is NULL");
	else
		return msubscriberIdentity;
}

RequestedInfo* AnyTimeInterrogationArg::getrequestedInfo() {//throw(const char*)
	if(NULL == mrequestedInfo)
		throw("Object requestedInfo is NULL");
	else
		return mrequestedInfo;
}

capstd::GENERIC* AnyTimeInterrogationArg::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

capstd::OctetString* AnyTimeInterrogationArg::getgsmSCF_Address() {//throw(const char*)
	if(NULL == mgsmSCF_Address)
		throw("Object gsmSCF_Address is NULL");
	else
		return mgsmSCF_Address;
}

bool AnyTimeInterrogationArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int AnyTimeInterrogationArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				if(NULL == this->setsubscriberIdentity())
					return -1;
				if(msubscriberIdentity->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setrequestedInfo())
					return -1;
				if(mrequestedInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded, mTagArray, AnyTimeInterrogationArg_EXTENSIONCONTAINER) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setgsmSCF_Address())
					return -1;
				if(mgsmSCF_Address->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: AnyTimeInterrogationArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("AnyTimeInterrogationArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int AnyTimeInterrogationArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("AnyTimeInterrogationArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case AnyTimeInterrogationArg_SUBSCRIBERIDENTITY:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msubscriberIdentity->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AnyTimeInterrogationArg_REQUESTEDINFO:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrequestedInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AnyTimeInterrogationArg_EXTENSIONCONTAINER:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AnyTimeInterrogationArg_GSMSCF_ADDRESS:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgsmSCF_Address->Encode(array) < 0) || 
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

int AnyTimeInterrogationArg::Display(int tab){
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
			case AnyTimeInterrogationArg_SUBSCRIBERIDENTITY:
			{
				printf(temp, " ", "subscriberIdentity");
				if(msubscriberIdentity->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AnyTimeInterrogationArg_REQUESTEDINFO:
			{
				printf(temp, " ", "requestedInfo");
				if(mrequestedInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AnyTimeInterrogationArg_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AnyTimeInterrogationArg_GSMSCF_ADDRESS:
			{
				printf(temp, " ", "gsmSCF_Address");
				if(mgsmSCF_Address->Display(tab+1) < 0)
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

bool AnyTimeInterrogationArg::ValidateMandatory(char *errStr){
	if(NULL == msubscriberIdentity)
	{
		strcpy(errStr, "subscriberIdentity");
		return false;
	}
	else if(NULL == mrequestedInfo)
	{
		strcpy(errStr, "requestedInfo");
		return false;
	}
	else if(NULL == mgsmSCF_Address)
	{
		strcpy(errStr, "gsmSCF_Address");
		return false;
	}

	return true;
}
