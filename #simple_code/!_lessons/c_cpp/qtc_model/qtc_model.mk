##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=qtc_model
ConfigurationName      :=Debug
WorkspacePath          :=/home/jura/c_tutorial/C_CPP_tutorial/#simple_code/!_lessons/c_cpp
ProjectPath            :=/home/jura/c_tutorial/C_CPP_tutorial/#simple_code/!_lessons/c_cpp/qtc_model
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jura
Date                   :=29/08/19
CodeLitePath           :=/home/jura/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="qtc_model.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Singleton.cpp$(ObjectSuffix) $(IntermediateDirectory)/Rx.cpp$(ObjectSuffix) $(IntermediateDirectory)/Tx.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jura/c_tutorial/C_CPP_tutorial/#simple_code/!_lessons/c_cpp/qtc_model/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Singleton.cpp$(ObjectSuffix): Singleton.cpp $(IntermediateDirectory)/Singleton.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jura/c_tutorial/C_CPP_tutorial/#simple_code/!_lessons/c_cpp/qtc_model/Singleton.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Singleton.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Singleton.cpp$(DependSuffix): Singleton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Singleton.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Singleton.cpp$(DependSuffix) -MM Singleton.cpp

$(IntermediateDirectory)/Singleton.cpp$(PreprocessSuffix): Singleton.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Singleton.cpp$(PreprocessSuffix) Singleton.cpp

$(IntermediateDirectory)/Rx.cpp$(ObjectSuffix): Rx.cpp $(IntermediateDirectory)/Rx.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jura/c_tutorial/C_CPP_tutorial/#simple_code/!_lessons/c_cpp/qtc_model/Rx.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Rx.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Rx.cpp$(DependSuffix): Rx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Rx.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Rx.cpp$(DependSuffix) -MM Rx.cpp

$(IntermediateDirectory)/Rx.cpp$(PreprocessSuffix): Rx.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Rx.cpp$(PreprocessSuffix) Rx.cpp

$(IntermediateDirectory)/Tx.cpp$(ObjectSuffix): Tx.cpp $(IntermediateDirectory)/Tx.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jura/c_tutorial/C_CPP_tutorial/#simple_code/!_lessons/c_cpp/qtc_model/Tx.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tx.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tx.cpp$(DependSuffix): Tx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tx.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tx.cpp$(DependSuffix) -MM Tx.cpp

$(IntermediateDirectory)/Tx.cpp$(PreprocessSuffix): Tx.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tx.cpp$(PreprocessSuffix) Tx.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


