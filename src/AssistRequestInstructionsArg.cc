#include "AssistRequestInstructionsArg.h"

using namespace capphase3;

AssistRequestInstructionsArg::AssistRequestInstructionsArg()
{
	mcorrelationID = NULL;
	miPSSPCapabilities = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0082, 0X00A3};
	mTagOptional = {false, false, true};
}

AssistRequestInstructionsArg::~AssistRequestInstructionsArg()
{
	if(mcorrelationID != NULL)
		delete mcorrelationID;
	if(miPSSPCapabilities != NULL)
		delete miPSSPCapabilities;
	if(mextensions != NULL)
		delete mextensions;
}

capstd::OctetString* AssistRequestInstructionsArg::setcorrelationID(){
	if(mcorrelationID == NULL)
	{
		mcorrelationID = new capstd::OctetString(2, 16);
		mTagsPresent |= AssistRequestInstructionsArg_CORRELATIONID;
		return mcorrelationID;
	}
	else
		return mcorrelationID;

}

bool AssistRequestInstructionsArg::setcorrelationID(capstd::OctetString* correlationID){
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

capstd::OctetString* AssistRequestInstructionsArg::setiPSSPCapabilities(){
	if(miPSSPCapabilities == NULL)
	{
		miPSSPCapabilities = new capstd::OctetString(1, 4);
		mTagsPresent |= AssistRequestInstructionsArg_IPSSPCAPABILITIES;
		return miPSSPCapabilities;
	}
	else
		return miPSSPCapabilities;

}

bool AssistRequestInstructionsArg::setiPSSPCapabilities(capstd::OctetString* iPSSPCapabilities){
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

Extensions* AssistRequestInstructionsArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= AssistRequestInstructionsArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool AssistRequestInstructionsArg::setextensions(Extensions* extensions){
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

capstd::OctetString* AssistRequestInstructionsArg::getcorrelationID() {//throw(const char*)
	if(NULL == mcorrelationID)
		throw("Object correlationID is NULL");
	else
		return mcorrelationID;
}

capstd::OctetString* AssistRequestInstructionsArg::getiPSSPCapabilities() {//throw(const char*)
	if(NULL == miPSSPCapabilities)
		throw("Object iPSSPCapabilities is NULL");
	else
		return miPSSPCapabilities;
}

Extensions* AssistRequestInstructionsArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool AssistRequestInstructionsArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int AssistRequestInstructionsArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				if(NULL == this->setcorrelationID())
					return -1;
				if(mcorrelationID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setiPSSPCapabilities())
					return -1;
				if(miPSSPCapabilities->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A3:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: AssistRequestInstructionsArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("AssistRequestInstructionsArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int AssistRequestInstructionsArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("AssistRequestInstructionsArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case AssistRequestInstructionsArg_CORRELATIONID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcorrelationID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AssistRequestInstructionsArg_IPSSPCAPABILITIES:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((miPSSPCapabilities->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AssistRequestInstructionsArg_EXTENSIONS:
				if(asn1_tag_encode(163, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
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

int AssistRequestInstructionsArg::Display(int tab){
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
			case AssistRequestInstructionsArg_CORRELATIONID:
			{
				printf(temp, " ", "correlationID");
				if(mcorrelationID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AssistRequestInstructionsArg_IPSSPCAPABILITIES:
			{
				printf(temp, " ", "iPSSPCapabilities");
				if(miPSSPCapabilities->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AssistRequestInstructionsArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
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

bool AssistRequestInstructionsArg::ValidateMandatory(char *errStr){
	if(NULL == mcorrelationID)
	{
		strcpy(errStr, "correlationID");
		return false;
	}
	else if(NULL == miPSSPCapabilities)
	{
		strcpy(errStr, "iPSSPCapabilities");
		return false;
	}

	return true;
}
