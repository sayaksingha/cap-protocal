# @(#) $Id: Makefile,v 1.1.2.5 2019/06/05 01:13:47 mrafi Exp $

ROOTDIR = $(PROJ_HOME)

include $(ROOTDIR)/makeutil/header.mod

#################################################################
# define the list of source files.
SRCS = 	CapDataTypes.cc\
			ApplyChargingReportArg.cc\
			ApplyChargingArg.cc\
			AssistRequestInstructionsArg.cc\
			CallGapArg.cc\
			CallInformationRequestArg.cc\
			CallInformationReportArg.cc\
			CancelArg.cc\
			ConnectArg.cc\
			ContinueWithArgumentArg.cc\
			ConnectToResourceArg.cc\
			EventReportBCSMArg.cc\
			EstablishTemporaryConnectionArg.cc\
			InitialDPArg.cc\
			RequestReportBCSMEventArg.cc\
			ReleaseCallArg.cc\
			ResetTimerArg.cc\
			RequestReportSMSEventArg.cc\
			SendChargingInformationArg.cc\
			#CapEncDecLib.cc\
			BasicDecoder.cc\
			AsnEncDec.cc\
			CapInterface.cc

			#DisconnectLegArg.cc\
			EntityReleasedArg.cc\
			DisconnectForwardConnectionWithArgumentArg.cc\
			MoveLegArg.cc\
			InitialDPSMSArg.cc\
			PlayToneArg.cc\
			ResetTimerSMSArg.cc\
			SplitLegArg.cc\


SRCS := $(SRCS:%=$(SRCDIR)/%)

#################################################################
# define the include flags.
INCLFLAGS = -I $(PROJ_HOME)/include\
				-I $(PROJ_HOME)\
				-I $(PROJ_HOME)/shm/include\
				-I $(PROJ_HOME)/util/include\
				-I $(PROJ_HOME)/shmstl/include\
				-I $(PROJ_HOME)/cap/common/include\
				-I $(PROJ_HOME)/cap/phase3/include\
				-I $(SIG_HOME)/include\
				-I $(SIG_HOME)/gtputil/include/ \
				-I $(UTIL_HOME)/include\
            -I $(UTIL_HOME)/log/include \
            -I $(UTIL_HOME)/peg/include \
            -I $(UTIL_HOME)/db/include \
            -I $(UTIL_HOME)/tssutil/include \
            -I $(UTIL_HOME)/trace/include\
            -I $(UTIL_HOME)/datastructures/include\
            -I $(UTIL_HOME)/semaphore/include\
            -I $(UTIL_HOME)/socket/include\
            -I $(UTIL_HOME)/strtok/include\
            -I $(UTIL_HOME)/msgq/include\
            -I $(UTIL_HOME)/shmq/include\
            -I $(UTIL_HOME)/timer/include\
            -I $(UTIL_HOME)/processlock/include\
            -I $(UTIL_HOME)/protocolstack/include\
				-I $(UTIL_HOME)/configinfo/include \
            -I $(SS7_HOME)/include\
            -I $(TP_HOME)/TDAPI/include \
            -I $(TP_HOME)/SQLAPI/include

# define the library flags.
LIBFLAGS = $(UTIL_HOME)/lib/libutil.a

# define the library flags.

LIBDIR = lib

#################################################################
# list of generated object files.
OBJS1 = CapDataTypes.o\
        ApplyChargingReportArg.o ApplyChargingArg.o AssistRequestInstructionsArg.o CallGapArg.o\
        CallInformationRequestArg.o CallInformationReportArg.o CancelArg.o\
        ConnectArg.o ContinueWithArgumentArg.o ConnectToResourceArg.o\
        EventReportBCSMArg.o EstablishTemporaryConnectionArg.o\
        InitialDPArg.o RequestReportBCSMEventArg.o ReleaseCallArg.o\
        ResetTimerArg.o SendChargingInformationArg.o\
		  #CapInterface.o CapEncDecLib.o BasicDecoder.o AsnEncDec.o\

		  #DisconnectLegArg.o\
		  DisconnectForwardConnectionWithArgumentArg.o EntityReleasedArg.o MoveLegArg.o InitialDPSMSArg.o PlayToneArg.o RequestReportSMSEventArg.o ResetTimerSMSArg.o SplitLegArg.o\

#OBJS1 = CapDataTypes.o InitialDPArg.o CapEncDecLib.o BasicDecoder.o AsnEncDec.o\
InitialDPSMSArg.o\
        CallInformationReportArg.o EventReportBCSMArg.o\
		  CallGapArg.o EstablishTemporaryConnectionArg.o\
		  ConnectSMSArg.o CallInformationRequestArg.o\
		  ReleaseCallArg.o CapInterface.o#NoteMMEventArg.o SSInvocationNotificationArg.o\
		  CapEncDecLib.o\
		  BasicDecoder.o temp.o

OBJS1 := $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1 = $(PROJ_HOME)/lib/libCapEncDec.so

# output file name.
OFILE1 = libCapPhase3.so

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

#################################################################
# List of all object files
OBJS = $(OBJS1) #$(OBJS2) $(OBJS3) $(OBJS6) $(OBJS7) $(OBJS9) $(OBJS10) $(OBJS11) $(OBJS12)

# List of all executables to be created
PROG = 
PROG := $(PROG:%=$(BINDIR)/%)  

# List of all libraries to be created
#OLIB = $(OFILE1) #$(OFILE2) $(OFILE3) $(OFILE6) $(OFILE7) $(OFILE9) $(OFILE10) $(OFILE11) $(OFILE12)
#OLIB := $(OLIB:%=$(LIBDIR)/%)

OSLIB = $(OFILE1)
OSLIB := $(OSLIB:%=$(LIBDIR)/%)
#################################################################

include $(ROOTDIR)/makeutil/footer.mod
