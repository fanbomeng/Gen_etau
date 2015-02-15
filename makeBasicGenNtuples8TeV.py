import FWCore.ParameterSet.Config as cms
import os

  
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing('analysis')
options.outputFile = "BasicGenInfo.root"
options.parseArguments()
process = cms.Process('BasicGenInfo')

process.load('Configuration.StandardSequences.Services_cff')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.Geometry.GeometryIdeal_cff')\

# Make the framework shut up.
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 2000

# Spit out filter efficiency at the end.
#process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

#Max Events
process.maxEvents = cms.untracked.PSet(
	input = cms.untracked.int32(-1)
)

#Input
process.source = cms.Source("PoolSource",
#	fileNames = cms.untracked.vstring('root://xrootd-cms.infn.it//eoscms.cern.ch//eos/cms/store/user/fmeng/Hetau/GGToHetau_13TeV_pythia8_cff_py_GEN_PU_10_1_vX5.root')
	fileNames = cms.untracked.vstring('root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_10_1_vcv.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_11_1_UBX.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_1_1_A4J.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_12_1_B8i.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_13_1_Qsp.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_14_1_alP.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_15_1_sr4.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_16_1_FV0.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_17_1_ysk.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_18_1_jAq.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_19_1_JZL.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_20_1_oMv.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_2_1_oBW.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_3_1_g3F.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_4_1_kfc.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_5_1_yma.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_6_1_r1q.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_7_1_QJQ.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_8_1_CCe.root',
	'root://cmsxrootd.hep.wisc.edu//store/user/fmeng/inputs/Hetau8TeV/GGToHetau_8TeV_pythia8_cff_py_GEN_PU_9_1_kcI.root')
#	fileNames = cms.untracked.vstring('file:/afs/hep.wisc.edu/home/fmeng/Fanbo/LFVetau/src/FinalStateAnalysis/NtupleTools/python/GGToHetau_13TeV_pythia8_cff_py_GEN_PU_11_1_PXn.root')
    #    fileNames = cms.untracked.vstring("root://eoscms.cern.ch//eos/cms/store/user/fmeng/Hetau/GGToHetau_13TeV_pythia8_cff_py_GEN_PU_10_1_vX5.root")
)

#Output
process.TFileService = cms.Service(
	"TFileService",
	fileName = cms.string("GGHetau8TeV.root")
)


process.BasicGenInfo = cms.EDFilter(
	"BasicGenPlotter",
)


process.p1 = cms.Path(
	process.BasicGenInfo
)

process.schedule = cms.Schedule(
	process.p1,
)
