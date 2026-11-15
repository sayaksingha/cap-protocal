#include "ConnectSMSArg.h"

using namespace capphase3;

ConnectSMSArg::ConnectSMSArg()
{
	mcallingPartysNumber = NULL;
	mdestinationSubscriberNumber = NULL;
	msMSCAddress = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0080, 0X00AA};
	mTagOptional = {true, true, true, true};
}

ConnectSMSArg::~ConnectSMSArg()
{
	if(mcallingPartysNumber != NULL)
		delete mcallingPartysNumber;
	if(mdestinationSubscriberNumber != NULL)
		delete mdestinationSubscriberNumber;
	if(msMSCAddress != NULL)
		delete msMSCAddress;
	if(mextensions != NULL)
		delete mextensions;
}

ISDN_AddressString* ConnectSMSArg::setcallingPartysNumber(){
	if(mcallingPartysNumber == NULL)
	{
		mcallingPartysNumber = new ISDN_AddressString();
		mTagsPresent |= ConnectSMSArg_CALLINGPARTYSNUMBER;
		return mcallingPartysNumber;
	}
	else
		return mcallingPartysNumber;

}

bool ConnectSMSArg::setcallingPartysNumber(ISDN_AddressString* callingPartysNumber){
	if(mcallingPartysNumber == NULL)
	{
		return -1;
	}
	else
	{
		mcallingPartysNumber = callingPartysNumber;
		return true;
	}

}

capstd::capstd::OctetString* ConnectSMSArg::setdestinationSubscriberNumber(){
	if(mdestinationSubscriberNumber == NULL)
	{
		mdestinationSubscriberNumber = new capstd::OctetString(1, 41);
		mTagsPresent |= ConnectSMSArg_DESTINATIONSUBSCRIBERNUMBER;
		return mdestinationSubscriberNumber;
	}
	else
		return mdestinationSubscriberNumber;

}

bool ConnectSMSArg::setdestinationSubscriberNumber(capstd::capstd::OctetString* destinationSubscriberNumber){
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

ISDN_AddressString* ConnectSMSArg::setsMSCAddress(){
	if(msMSCAddress == NULL)
	{
		msMSCAddress = new ISDN_AddressString();
		mTagsPresent |= ConnectSMSArg_SMSCADDRESS;
		return msMSCAddress;
	}
	else
		return msMSCAddress;

}

bool ConnectSMSArg::setsMSCAddress(ISDN_AddressString* sMSCAddress){
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

Extensions* ConnectSMSArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= ConnectSMSArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool ConnectSMSArg::setextensions(Extensions* extensions){
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

ISDN_AddressString* ConnectSMSArg::getcallingPartysNumber() {
	if(NULL == mcallingPartysNumber)
		throw("Object callingPartysNumber is NULL");
	else
		return mcallingPartysNumber;
}

capstd::capstd::OctetString* ConnectSMSArg::getdestinationSubscriberNumber() {
	if(NULL == mdestinationSubscriberNumber)
		throw("Object destinationSubscriberNumber is NULL");
	else
		return mdestinationSubscriberNumber;
}

ISDN_AddressString* ConnectSMSArg::getsMSCAddress() {
	if(NULL == msMSCAddress)
		throw("Object sMSCAddress is NULL");
	else
		return msMSCAddress;
}

Extensions* ConnectSMSArg::getextensions() {
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool ConnectSMSArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ConnectSMSArg::Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				if(!isPresent(ConnectSMSArg_CALLINGPARTYSNUMBER))
				{
					if(NULL == this->setcallingPartysNumber())
						return -1;
					if(mcallingPartysNumber->Decode(array, &bytesDecoded) < 0)
						decode = false;
				}
				else if(!isPresent(ConnectSMSArg_SMSCADDRESS))
				{
					if(NULL == this->setsMSCAddress())
						return -1;
					if(msMSCAddress->Decode(array, &bytesDecoded) < 0)
						decode = false;
				}
				break;
			case 0X00AA:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ConnectSMSArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ConnectSMSArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ConnectSMSArg::Encode(capstd::capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ConnectSMSArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case ConnectSMSArg_CALLINGPARTYSNUMBER:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingPartysNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectSMSArg_DESTINATIONSUBSCRIBERNUMBER:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mdestinationSubscriberNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectSMSArg_SMSCADDRESS:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msMSCAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ConnectSMSArg_EXTENSIONS:
				if(asn1_tag_encode(170, array) < 0)
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

int ConnectSMSArg::Display(int tab){
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
			case ConnectSMSArg_CALLINGPARTYSNUMBER:
			{
				printf(temp, " ", "callingPartysNumber");
				if(mcallingPartysNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectSMSArg_DESTINATIONSUBSCRIBERNUMBER:
			{
				printf(temp, " ", "destinationSubscriberNumber");
				if(mdestinationSubscriberNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectSMSArg_SMSCADDRESS:
			{
				printf(temp, " ", "sMSCAddress");
				if(msMSCAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ConnectSMSArg_EXTENSIONS:
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

bool ConnectSMSArg::ValidateMandatory(char *errStr){

	return true;
}
