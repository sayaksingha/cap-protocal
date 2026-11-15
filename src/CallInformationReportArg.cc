#include "CallInformationReportArg.h"

using namespace capphase3;

CallInformationReportArg::CallInformationReportArg()
{
	mrequestedInformationList = NULL;
	mextensions = NULL;
	mlegID = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A2, 0X00A3};
	mTagOptional = {false, true, true};
}

CallInformationReportArg::~CallInformationReportArg()
{
	if(mrequestedInformationList != NULL)
		delete mrequestedInformationList;
	if(mextensions != NULL)
		delete mextensions;
	if(mlegID != NULL)
		delete mlegID;
}

RequestedInformationList* CallInformationReportArg::setrequestedInformationList(){
	if(mrequestedInformationList == NULL)
	{
		mrequestedInformationList = new RequestedInformationList();
		mTagsPresent |= CallInformationReportArg_REQUESTEDINFORMATIONLIST;
		return mrequestedInformationList;
	}
	else
		return mrequestedInformationList;

}

bool CallInformationReportArg::setrequestedInformationList(RequestedInformationList* requestedInformationList){
	if(mrequestedInformationList == NULL)
	{
		return -1;
	}
	else
	{
		mrequestedInformationList = requestedInformationList;
		return true;
	}

}

Extensions* CallInformationReportArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= CallInformationReportArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool CallInformationReportArg::setextensions(Extensions* extensions){
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

ReceivingSideID* CallInformationReportArg::setlegID(){
	if(mlegID == NULL)
	{
		mlegID = new ReceivingSideID();
		mTagsPresent |= CallInformationReportArg_LEGID;
		return mlegID;
	}
	else
		return mlegID;

}

bool CallInformationReportArg::setlegID(ReceivingSideID* legID){
	if(mlegID == NULL)
	{
		return -1;
	}
	else
	{
		mlegID = legID;
		return true;
	}

}

RequestedInformationList* CallInformationReportArg::getrequestedInformationList() {//throw(const char*)
	if(NULL == mrequestedInformationList)
		throw("Object requestedInformationList is NULL");
	else
		return mrequestedInformationList;
}

Extensions* CallInformationReportArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

ReceivingSideID* CallInformationReportArg::getlegID() {//throw(const char*)
	if(NULL == mlegID)
		throw("Object legID is NULL");
	else
		return mlegID;
}

bool CallInformationReportArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CallInformationReportArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				if(NULL == this->setrequestedInformationList())
					return -1;
				if(mrequestedInformationList->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A3:
				if(NULL == this->setlegID())
					return -1;
				if(mlegID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: CallInformationReportArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CallInformationReportArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CallInformationReportArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CallInformationReportArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case CallInformationReportArg_REQUESTEDINFORMATIONLIST:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrequestedInformationList->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CallInformationReportArg_EXTENSIONS:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CallInformationReportArg_LEGID:
				if(asn1_tag_encode(163, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlegID->Encode(array) < 0) || 
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

int CallInformationReportArg::Display(int tab){
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
			case CallInformationReportArg_REQUESTEDINFORMATIONLIST:
			{
				printf(temp, " ", "requestedInformationList");
				if(mrequestedInformationList->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CallInformationReportArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CallInformationReportArg_LEGID:
			{
				printf(temp, " ", "legID");
				if(mlegID->Display(tab+1) < 0)
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

bool CallInformationReportArg::ValidateMandatory(char *errStr){
	if(NULL == mrequestedInformationList)
	{
		strcpy(errStr, "requestedInformationList");
		return false;
	}

	return true;
}
