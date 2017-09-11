#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TPad.h"


////////// Global Variables //////////

   double Trigger_SF, Trigger_SF_UP, Trigger_SF_DOWN, MuonTrack_SF, Muon_SF, Muon_SF_UP, Muon_SF_DOWN, MuonISO_SF, MuonISO_SF_UP, MuonISO_SF_DOWN;
   double weight_by_trigger, weight, MCweight, PU, PU_UP, PU_DOWN, BTag_SF;
   double nbtags, nVer, njets, Mu_Pt, Mu_Eta, METv, jet_Pt1, jet_Pt2, jet_Pt3, jet_Pt4, jet_Eta1, jet_Eta2, jet_Eta3, jet_Eta4;
   double jet_btag1, jet_btag2, jet_btag3, jet_btag4, iso04, Mistag_Rate_2b;

////////// Main Fucntion ///////////

void CTRL_PLOTS_CH_13TeV_pT(){

	gROOT->LoadMacro("tdrstyle.C");
	setTDRStyle();
	gStyle->SetPadTopMargin(0.1);

   TFile *MC[17], *MC_antiiso[17];

   MC[0] = new TFile("CHMuJets3_SKTT_powheg_cat_v8-0-7.root");
   MC[1] = new TFile("CHMuJets3_SKWJets_cat_v8-0-7.root");
   MC[2] = new TFile("CHMuJets3_SKDYJets_cat_v8-0-7.root");
   MC[3] = new TFile("CHMuJets3_SKSingleTop_s_cat_v8-0-7.root");
   MC[4] = new TFile("CHMuJets3_SKSingleTop_t_cat_v8-0-7.root");
   MC[5] = new TFile("CHMuJets3_SKSingleTop_tW_noHadron_cat_v8-0-7.root");
   MC[6] = new TFile("CHMuJets3_SKSingleTop_tW_cat_v8-0-7.root");
   MC[7] = new TFile("CHMuJets3_SKSingleTbar_t_cat_v8-0-7.root");
   MC[8] = new TFile("CHMuJets3_SKSingleTbar_tW_noHadron_cat_v8-0-7.root");
   MC[9] = new TFile("CHMuJets3_SKSingleTbar_tW_cat_v8-0-7.root");
   MC[10] = new TFile("CHMuJets3_SKWW_cat_v8-0-7.root");
   MC[11] = new TFile("CHMuJets3_SKZZ_cat_v8-0-7.root");
   MC[12] = new TFile("CHMuJets3_SKWZ_cat_v8-0-7.root");
   MC[13] = new TFile("CHMuJets3_SKttW_cat_v8-0-7.root");
   MC[14] = new TFile("CHMuJets3_SKttZ_cat_v8-0-7.root");
   MC[15] = new TFile("CHMuJets3_SKttH_bb_cat_v8-0-7.root");
   MC[16] = new TFile("CHMuJets3_SKttH_nonbb_cat_v8-0-7.root");

   MC_antiiso[0] = new TFile("CHMuJets3_antiiso_SKTT_powheg_cat_v8-0-7.root");
   MC_antiiso[1] = new TFile("CHMuJets3_antiiso_SKWJets_cat_v8-0-7.root");
   MC_antiiso[2] = new TFile("CHMuJets3_antiiso_SKDYJets_cat_v8-0-7.root");
   MC_antiiso[3] = new TFile("CHMuJets3_antiiso_SKSingleTop_s_cat_v8-0-7.root");
   MC_antiiso[4] = new TFile("CHMuJets3_antiiso_SKSingleTop_t_cat_v8-0-7.root");
   MC_antiiso[5] = new TFile("CHMuJets3_antiiso_SKSingleTop_tW_noHadron_cat_v8-0-7.root");
   MC_antiiso[6] = new TFile("CHMuJets3_antiiso_SKSingleTop_tW_cat_v8-0-7.root");
   MC_antiiso[7] = new TFile("CHMuJets3_antiiso_SKSingleTbar_t_cat_v8-0-7.root");
   MC_antiiso[8] = new TFile("CHMuJets3_antiiso_SKSingleTbar_tW_noHadron_cat_v8-0-7.root");
   MC_antiiso[9] = new TFile("CHMuJets3_antiiso_SKSingleTbar_tW_cat_v8-0-7.root");
   MC_antiiso[10] = new TFile("CHMuJets3_antiiso_SKWW_cat_v8-0-7.root");
   MC_antiiso[11] = new TFile("CHMuJets3_antiiso_SKZZ_cat_v8-0-7.root");
   MC_antiiso[12] = new TFile("CHMuJets3_antiiso_SKWZ_cat_v8-0-7.root");
   MC_antiiso[13] = new TFile("CHMuJets3_antiiso_SKttW_cat_v8-0-7.root");
   MC_antiiso[14] = new TFile("CHMuJets3_antiiso_SKttZ_cat_v8-0-7.root");
   MC_antiiso[15] = new TFile("CHMuJets3_antiiso_SKttH_bb_cat_v8-0-7.root");
   MC_antiiso[16] = new TFile("CHMuJets3_antiiso_SKttH_nonbb_cat_v8-0-7.root");


   DATA = new TFile("CHMuJets3_data_SingleMuon_cat_v8-0-7.root");
   DATA_antiiso = new TFile("CHMuJets3_antiiso_data_SingleMuon_cat_v8-0-7.root");

   TNtuple *MC_t[17], *DATA_t, *MC_antiiso_t[17], *DATA_antiiso_t;

	 for(int i=0; i<17; i++) SetBranchAddress(MC_t[i], MC[i]);
	 for(int i=0; i<17; i++) SetBranchAddress(MC_antiiso_t[i], MC_antiiso[i]);

	 SetBranchAddress(DATA_t, DATA);
	 SetBranchAddress(DATA_antiiso_t, DATA_antiiso);



  //pT_1
  TH1F *h_TT_pT_1_1b =new TH1F("h_TT_pT_1_1b", "h_TT_pT_1_1b", 60, 0, 300);
  TH1F *h_TT_pT_1_2b =new TH1F("h_TT_pT_1_2b", "h_TT_pT_1_2b", 60, 0, 300);
  TH1F *h_TT_pT_1_3b =new TH1F("h_TT_pT_1_3b", "h_TT_pT_1_3b", 60, 0, 300);
  TH1F *h_VJ_pT_1_1b =new TH1F("h_VJ_pT_1_1b", "h_VJ_pT_1_1b", 60, 0, 300);
  TH1F *h_VJ_pT_1_2b =new TH1F("h_VJ_pT_1_2b", "h_VJ_pT_1_2b", 60, 0, 300);
  TH1F *h_VJ_pT_1_3b =new TH1F("h_VJ_pT_1_3b", "h_VJ_pT_1_3b", 60, 0, 300);
  TH1F *h_ST_pT_1_1b =new TH1F("h_ST_pT_1_1b", "h_ST_pT_1_1b", 60, 0, 300);
  TH1F *h_ST_pT_1_2b =new TH1F("h_ST_pT_1_2b", "h_ST_pT_1_2b", 60, 0, 300);
  TH1F *h_ST_pT_1_3b =new TH1F("h_ST_pT_1_3b", "h_ST_pT_1_3b", 60, 0, 300);
  TH1F *h_VV_pT_1_1b =new TH1F("h_VV_pT_1_1b", "h_VV_pT_1_1b", 60, 0, 300);
  TH1F *h_VV_pT_1_2b =new TH1F("h_VV_pT_1_2b", "h_VV_pT_1_2b", 60, 0, 300);
  TH1F *h_VV_pT_1_3b =new TH1F("h_VV_pT_1_3b", "h_VV_pT_1_3b", 60, 0, 300);
  TH1F *h_QCD_pT_1_1b =new TH1F("h_QCD_pT_1_1b", "h_QCD_pT_1_1b", 60, 0, 300);
  TH1F *h_QCD_pT_1_2b =new TH1F("h_QCD_pT_1_2b", "h_QCD_pT_1_2b", 60, 0, 300);
  TH1F *h_QCD_pT_1_3b =new TH1F("h_QCD_pT_1_3b", "h_QCD_pT_1_3b", 60, 0, 300);
  TH1F *h_TTX_pT_1_1b =new TH1F("h_TTX_pT_1_1b", "h_TTX_pT_1_1b", 60, 0, 300);
  TH1F *h_TTX_pT_1_2b =new TH1F("h_TTX_pT_1_2b", "h_TTX_pT_1_2b", 60, 0, 300);
  TH1F *h_TTX_pT_1_3b =new TH1F("h_TTX_pT_1_3b", "h_TTX_pT_1_3b", 60, 0, 300);

  //pT_2
  TH1F *h_TT_pT_2_1b =new TH1F("h_TT_pT_2_1b", "h_TT_pT_2_1b", 60, 0, 300);
  TH1F *h_TT_pT_2_2b =new TH1F("h_TT_pT_2_2b", "h_TT_pT_2_2b", 60, 0, 300);
  TH1F *h_TT_pT_2_3b =new TH1F("h_TT_pT_2_3b", "h_TT_pT_2_3b", 60, 0, 300);
  TH1F *h_VJ_pT_2_1b =new TH1F("h_VJ_pT_2_1b", "h_VJ_pT_2_1b", 60, 0, 300);
  TH1F *h_VJ_pT_2_2b =new TH1F("h_VJ_pT_2_2b", "h_VJ_pT_2_2b", 60, 0, 300);
  TH1F *h_VJ_pT_2_3b =new TH1F("h_VJ_pT_2_3b", "h_VJ_pT_2_3b", 60, 0, 300);
  TH1F *h_ST_pT_2_1b =new TH1F("h_ST_pT_2_1b", "h_ST_pT_2_1b", 60, 0, 300);
  TH1F *h_ST_pT_2_2b =new TH1F("h_ST_pT_2_2b", "h_ST_pT_2_2b", 60, 0, 300);
  TH1F *h_ST_pT_2_3b =new TH1F("h_ST_pT_2_3b", "h_ST_pT_2_3b", 60, 0, 300);
  TH1F *h_VV_pT_2_1b =new TH1F("h_VV_pT_2_1b", "h_VV_pT_2_1b", 60, 0, 300);
  TH1F *h_VV_pT_2_2b =new TH1F("h_VV_pT_2_2b", "h_VV_pT_2_2b", 60, 0, 300);
  TH1F *h_VV_pT_2_3b =new TH1F("h_VV_pT_2_3b", "h_VV_pT_2_3b", 60, 0, 300);
  TH1F *h_QCD_pT_2_1b =new TH1F("h_QCD_pT_2_1b", "h_QCD_pT_2_1b", 60, 0, 300);
  TH1F *h_QCD_pT_2_2b =new TH1F("h_QCD_pT_2_2b", "h_QCD_pT_2_2b", 60, 0, 300);
  TH1F *h_QCD_pT_2_3b =new TH1F("h_QCD_pT_2_3b", "h_QCD_pT_2_3b", 60, 0, 300);
  TH1F *h_TTX_pT_2_1b =new TH1F("h_TTX_pT_2_1b", "h_TTX_pT_2_1b", 60, 0, 300);
  TH1F *h_TTX_pT_2_2b =new TH1F("h_TTX_pT_2_2b", "h_TTX_pT_2_2b", 60, 0, 300);
  TH1F *h_TTX_pT_2_3b =new TH1F("h_TTX_pT_2_3b", "h_TTX_pT_2_3b", 60, 0, 300);

  //pT_3
  TH1F *h_TT_pT_3_1b =new TH1F("h_TT_pT_3_1b", "h_TT_pT_3_1b", 60, 0, 300);
  TH1F *h_TT_pT_3_2b =new TH1F("h_TT_pT_3_2b", "h_TT_pT_3_2b", 60, 0, 300);
  TH1F *h_TT_pT_3_3b =new TH1F("h_TT_pT_3_3b", "h_TT_pT_3_3b", 60, 0, 300);
  TH1F *h_VJ_pT_3_1b =new TH1F("h_VJ_pT_3_1b", "h_VJ_pT_3_1b", 60, 0, 300);
  TH1F *h_VJ_pT_3_2b =new TH1F("h_VJ_pT_3_2b", "h_VJ_pT_3_2b", 60, 0, 300);
  TH1F *h_VJ_pT_3_3b =new TH1F("h_VJ_pT_3_3b", "h_VJ_pT_3_3b", 60, 0, 300);
  TH1F *h_ST_pT_3_1b =new TH1F("h_ST_pT_3_1b", "h_ST_pT_3_1b", 60, 0, 300);
  TH1F *h_ST_pT_3_2b =new TH1F("h_ST_pT_3_2b", "h_ST_pT_3_2b", 60, 0, 300);
  TH1F *h_ST_pT_3_3b =new TH1F("h_ST_pT_3_3b", "h_ST_pT_3_3b", 60, 0, 300);
  TH1F *h_VV_pT_3_1b =new TH1F("h_VV_pT_3_1b", "h_VV_pT_3_1b", 60, 0, 300);
  TH1F *h_VV_pT_3_2b =new TH1F("h_VV_pT_3_2b", "h_VV_pT_3_2b", 60, 0, 300);
  TH1F *h_VV_pT_3_3b =new TH1F("h_VV_pT_3_3b", "h_VV_pT_3_3b", 60, 0, 300);
  TH1F *h_QCD_pT_3_1b =new TH1F("h_QCD_pT_3_1b", "h_QCD_pT_3_1b", 60, 0, 300);
  TH1F *h_QCD_pT_3_2b =new TH1F("h_QCD_pT_3_2b", "h_QCD_pT_3_2b", 60, 0, 300);
  TH1F *h_QCD_pT_3_3b =new TH1F("h_QCD_pT_3_3b", "h_QCD_pT_3_3b", 60, 0, 300);
  TH1F *h_TTX_pT_3_1b =new TH1F("h_TTX_pT_3_1b", "h_TTX_pT_3_1b", 60, 0, 300);
  TH1F *h_TTX_pT_3_2b =new TH1F("h_TTX_pT_3_2b", "h_TTX_pT_3_2b", 60, 0, 300);
  TH1F *h_TTX_pT_3_3b =new TH1F("h_TTX_pT_3_3b", "h_TTX_pT_3_3b", 60, 0, 300);

  //pT_4
  TH1F *h_TT_pT_4_1b =new TH1F("h_TT_pT_4_1b", "h_TT_pT_4_1b", 60, 0, 300);
  TH1F *h_TT_pT_4_2b =new TH1F("h_TT_pT_4_2b", "h_TT_pT_4_2b", 60, 0, 300);
  TH1F *h_TT_pT_4_3b =new TH1F("h_TT_pT_4_3b", "h_TT_pT_4_3b", 60, 0, 300);
  TH1F *h_VJ_pT_4_1b =new TH1F("h_VJ_pT_4_1b", "h_VJ_pT_4_1b", 60, 0, 300);
  TH1F *h_VJ_pT_4_2b =new TH1F("h_VJ_pT_4_2b", "h_VJ_pT_4_2b", 60, 0, 300);
  TH1F *h_VJ_pT_4_3b =new TH1F("h_VJ_pT_4_3b", "h_VJ_pT_4_3b", 60, 0, 300);
  TH1F *h_ST_pT_4_1b =new TH1F("h_ST_pT_4_1b", "h_ST_pT_4_1b", 60, 0, 300);
  TH1F *h_ST_pT_4_2b =new TH1F("h_ST_pT_4_2b", "h_ST_pT_4_2b", 60, 0, 300);
  TH1F *h_ST_pT_4_3b =new TH1F("h_ST_pT_4_3b", "h_ST_pT_4_3b", 60, 0, 300);
  TH1F *h_VV_pT_4_1b =new TH1F("h_VV_pT_4_1b", "h_VV_pT_4_1b", 60, 0, 300);
  TH1F *h_VV_pT_4_2b =new TH1F("h_VV_pT_4_2b", "h_VV_pT_4_2b", 60, 0, 300);
  TH1F *h_VV_pT_4_3b =new TH1F("h_VV_pT_4_3b", "h_VV_pT_4_3b", 60, 0, 300);
  TH1F *h_QCD_pT_4_1b =new TH1F("h_QCD_pT_4_1b", "h_QCD_pT_4_1b", 60, 0, 300);
  TH1F *h_QCD_pT_4_2b =new TH1F("h_QCD_pT_4_2b", "h_QCD_pT_4_2b", 60, 0, 300);
  TH1F *h_QCD_pT_4_3b =new TH1F("h_QCD_pT_4_3b", "h_QCD_pT_4_3b", 60, 0, 300);
  TH1F *h_TTX_pT_4_1b =new TH1F("h_TTX_pT_4_1b", "h_TTX_pT_4_1b", 60, 0, 300);
  TH1F *h_TTX_pT_4_2b =new TH1F("h_TTX_pT_4_2b", "h_TTX_pT_4_2b", 60, 0, 300);
  TH1F *h_TTX_pT_4_3b =new TH1F("h_TTX_pT_4_3b", "h_TTX_pT_4_3b", 60, 0, 300);

  //pT_mu
  TH1F *h_TT_pT_mu_1b =new TH1F("h_TT_pT_mu_1b", "h_TT_pT_mu_1b", 60, 0, 300);
  TH1F *h_TT_pT_mu_2b =new TH1F("h_TT_pT_mu_2b", "h_TT_pT_mu_2b", 60, 0, 300);
  TH1F *h_TT_pT_mu_3b =new TH1F("h_TT_pT_mu_3b", "h_TT_pT_mu_3b", 60, 0, 300);
  TH1F *h_VJ_pT_mu_1b =new TH1F("h_VJ_pT_mu_1b", "h_VJ_pT_mu_1b", 60, 0, 300);
  TH1F *h_VJ_pT_mu_2b =new TH1F("h_VJ_pT_mu_2b", "h_VJ_pT_mu_2b", 60, 0, 300);
  TH1F *h_VJ_pT_mu_3b =new TH1F("h_VJ_pT_mu_3b", "h_VJ_pT_mu_3b", 60, 0, 300);
  TH1F *h_ST_pT_mu_1b =new TH1F("h_ST_pT_mu_1b", "h_ST_pT_mu_1b", 60, 0, 300);
  TH1F *h_ST_pT_mu_2b =new TH1F("h_ST_pT_mu_2b", "h_ST_pT_mu_2b", 60, 0, 300);
  TH1F *h_ST_pT_mu_3b =new TH1F("h_ST_pT_mu_3b", "h_ST_pT_mu_3b", 60, 0, 300);
  TH1F *h_VV_pT_mu_1b =new TH1F("h_VV_pT_mu_1b", "h_VV_pT_mu_1b", 60, 0, 300);
  TH1F *h_VV_pT_mu_2b =new TH1F("h_VV_pT_mu_2b", "h_VV_pT_mu_2b", 60, 0, 300);
  TH1F *h_VV_pT_mu_3b =new TH1F("h_VV_pT_mu_3b", "h_VV_pT_mu_3b", 60, 0, 300);
  TH1F *h_QCD_pT_mu_1b =new TH1F("h_QCD_pT_mu_1b", "h_QCD_pT_mu_1b", 60, 0, 300);
  TH1F *h_QCD_pT_mu_2b =new TH1F("h_QCD_pT_mu_2b", "h_QCD_pT_mu_2b", 60, 0, 300);
  TH1F *h_QCD_pT_mu_3b =new TH1F("h_QCD_pT_mu_3b", "h_QCD_pT_mu_3b", 60, 0, 300);
  TH1F *h_TTX_pT_mu_1b =new TH1F("h_TTX_pT_mu_1b", "h_TTX_pT_mu_1b", 60, 0, 300);
  TH1F *h_TTX_pT_mu_2b =new TH1F("h_TTX_pT_mu_2b", "h_TTX_pT_mu_2b", 60, 0, 300);
  TH1F *h_TTX_pT_mu_3b =new TH1F("h_TTX_pT_mu_3b", "h_TTX_pT_mu_3b", 60, 0, 300);



   //pT_1
   h_TT_pT_1_1b ->Sumw2();
   h_TT_pT_1_2b ->Sumw2();
   h_TT_pT_1_3b ->Sumw2();
   h_VJ_pT_1_1b ->Sumw2();
   h_VJ_pT_1_2b ->Sumw2();
   h_VJ_pT_1_3b ->Sumw2();
   h_ST_pT_1_1b ->Sumw2();
   h_ST_pT_1_2b ->Sumw2();
   h_ST_pT_1_3b ->Sumw2();
   h_VV_pT_1_1b ->Sumw2();
   h_VV_pT_1_2b ->Sumw2();
   h_VV_pT_1_3b ->Sumw2();
   h_QCD_pT_1_1b ->Sumw2();
   h_QCD_pT_1_2b ->Sumw2();
   h_QCD_pT_1_3b ->Sumw2();
   h_TTX_pT_1_1b ->Sumw2();
   h_TTX_pT_1_2b ->Sumw2();
   h_TTX_pT_1_3b ->Sumw2();

   //pT_2
   h_TT_pT_2_1b ->Sumw2();
   h_TT_pT_2_2b ->Sumw2();
   h_TT_pT_2_3b ->Sumw2();
   h_VJ_pT_2_1b ->Sumw2();
   h_VJ_pT_2_2b ->Sumw2();
   h_VJ_pT_2_3b ->Sumw2();
   h_ST_pT_2_1b ->Sumw2();
   h_ST_pT_2_2b ->Sumw2();
   h_ST_pT_2_3b ->Sumw2();
   h_VV_pT_2_1b ->Sumw2();
   h_VV_pT_2_2b ->Sumw2();
   h_VV_pT_2_3b ->Sumw2();
   h_QCD_pT_2_1b ->Sumw2();
   h_QCD_pT_2_2b ->Sumw2();
   h_QCD_pT_2_3b ->Sumw2();
   h_TTX_pT_2_1b ->Sumw2();
   h_TTX_pT_2_2b ->Sumw2();
   h_TTX_pT_2_3b ->Sumw2();

   //pT_3
   h_TT_pT_3_1b ->Sumw2();
   h_TT_pT_3_2b ->Sumw2();
   h_TT_pT_3_3b ->Sumw2();
   h_VJ_pT_3_1b ->Sumw2();
   h_VJ_pT_3_2b ->Sumw2();
   h_VJ_pT_3_3b ->Sumw2();
   h_ST_pT_3_1b ->Sumw2();
   h_ST_pT_3_2b ->Sumw2();
   h_ST_pT_3_3b ->Sumw2();
   h_VV_pT_3_1b ->Sumw2();
   h_VV_pT_3_2b ->Sumw2();
   h_VV_pT_3_3b ->Sumw2();
   h_QCD_pT_3_1b ->Sumw2();
   h_QCD_pT_3_2b ->Sumw2();
   h_QCD_pT_3_3b ->Sumw2();
   h_TTX_pT_3_1b ->Sumw2();
   h_TTX_pT_3_2b ->Sumw2();
   h_TTX_pT_3_3b ->Sumw2();

   //pT_4
   h_TT_pT_4_1b ->Sumw2();
   h_TT_pT_4_2b ->Sumw2();
   h_TT_pT_4_3b ->Sumw2();
   h_VJ_pT_4_1b ->Sumw2();
   h_VJ_pT_4_2b ->Sumw2();
   h_VJ_pT_4_3b ->Sumw2();
   h_ST_pT_4_1b ->Sumw2();
   h_ST_pT_4_2b ->Sumw2();
   h_ST_pT_4_3b ->Sumw2();
   h_VV_pT_4_1b ->Sumw2();
   h_VV_pT_4_2b ->Sumw2();
   h_VV_pT_4_3b ->Sumw2();
   h_QCD_pT_4_1b ->Sumw2();
   h_QCD_pT_4_2b ->Sumw2();
   h_QCD_pT_4_3b ->Sumw2();
   h_TTX_pT_4_1b ->Sumw2();
   h_TTX_pT_4_2b ->Sumw2();
   h_TTX_pT_4_3b ->Sumw2();

   //pT_mu
   h_TT_pT_mu_1b ->Sumw2();
   h_TT_pT_mu_2b ->Sumw2();
   h_TT_pT_mu_3b ->Sumw2();
   h_VJ_pT_mu_1b ->Sumw2();
   h_VJ_pT_mu_2b ->Sumw2();
   h_VJ_pT_mu_3b ->Sumw2();
   h_ST_pT_mu_1b ->Sumw2();
   h_ST_pT_mu_2b ->Sumw2();
   h_ST_pT_mu_3b ->Sumw2();
   h_VV_pT_mu_1b ->Sumw2();
   h_VV_pT_mu_2b ->Sumw2();
   h_VV_pT_mu_3b ->Sumw2();
   h_QCD_pT_mu_1b ->Sumw2();
   h_QCD_pT_mu_2b ->Sumw2();
   h_QCD_pT_mu_3b ->Sumw2();
   h_TTX_pT_mu_1b ->Sumw2();
   h_TTX_pT_mu_2b ->Sumw2();
   h_TTX_pT_mu_3b ->Sumw2();




  //pT_1
  TH1F *h_DATA_pT_1_1b =new TH1F("h_DATA_pT_1_1b", "h_DATA_pT_1_1b", 60, 0, 300);
  TH1F *h_DATA_pT_1_2b =new TH1F("h_DATA_pT_1_2b", "h_DATA_pT_1_2b", 60, 0, 300);
  TH1F *h_DATA_pT_1_3b =new TH1F("h_DATA_pT_1_3b", "h_DATA_pT_1_3b", 60, 0, 300);

   //pT_1
   h_DATA_pT_1_1b ->Sumw2();
   h_DATA_pT_1_2b ->Sumw2();
   h_DATA_pT_1_3b ->Sumw2();

  //pT_2
  TH1F *h_DATA_pT_2_1b =new TH1F("h_DATA_pT_2_1b", "h_DATA_pT_2_1b", 60, 0, 300);
  TH1F *h_DATA_pT_2_2b =new TH1F("h_DATA_pT_2_2b", "h_DATA_pT_2_2b", 60, 0, 300);
  TH1F *h_DATA_pT_2_3b =new TH1F("h_DATA_pT_2_3b", "h_DATA_pT_2_3b", 60, 0, 300);

   //pT_2
   h_DATA_pT_2_1b ->Sumw2();
   h_DATA_pT_2_2b ->Sumw2();
   h_DATA_pT_2_3b ->Sumw2();

  //pT_3
  TH1F *h_DATA_pT_3_1b =new TH1F("h_DATA_pT_3_1b", "h_DATA_pT_3_1b", 60, 0, 300);
  TH1F *h_DATA_pT_3_2b =new TH1F("h_DATA_pT_3_2b", "h_DATA_pT_3_2b", 60, 0, 300);
  TH1F *h_DATA_pT_3_3b =new TH1F("h_DATA_pT_3_3b", "h_DATA_pT_3_3b", 60, 0, 300);

   //pT_3
   h_DATA_pT_3_1b ->Sumw2();
   h_DATA_pT_3_2b ->Sumw2();
   h_DATA_pT_3_3b ->Sumw2();

  //pT_4
  TH1F *h_DATA_pT_4_1b =new TH1F("h_DATA_pT_4_1b", "h_DATA_pT_4_1b", 60, 0, 300);
  TH1F *h_DATA_pT_4_2b =new TH1F("h_DATA_pT_4_2b", "h_DATA_pT_4_2b", 60, 0, 300);
  TH1F *h_DATA_pT_4_3b =new TH1F("h_DATA_pT_4_3b", "h_DATA_pT_4_3b", 60, 0, 300);

   //pT_4
   h_DATA_pT_4_1b ->Sumw2();
   h_DATA_pT_4_2b ->Sumw2();
   h_DATA_pT_4_3b ->Sumw2();

  //pT_mu
  TH1F *h_DATA_pT_mu_1b =new TH1F("h_DATA_pT_mu_1b", "h_DATA_pT_mu_1b", 60, 0, 300);
  TH1F *h_DATA_pT_mu_2b =new TH1F("h_DATA_pT_mu_2b", "h_DATA_pT_mu_2b", 60, 0, 300);
  TH1F *h_DATA_pT_mu_3b =new TH1F("h_DATA_pT_mu_3b", "h_DATA_pT_mu_3b", 60, 0, 300);

   //pT_mu
   h_DATA_pT_mu_1b ->Sumw2();
   h_DATA_pT_mu_2b ->Sumw2();
   h_DATA_pT_mu_3b ->Sumw2();

   double Scale =0.95;


   for (int i=0; i<1; i++){ //TT
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv<20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut

      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale;               //*36.4466098;
      if(nbtags==1){
           h_TT_pT_1_1b -> Fill(jet_Pt1,weight_SF);
           h_TT_pT_2_1b -> Fill(jet_Pt2,weight_SF);
           h_TT_pT_3_1b -> Fill(jet_Pt3,weight_SF);
           h_TT_pT_4_1b -> Fill(jet_Pt4,weight_SF);
           h_TT_pT_mu_1b -> Fill(Mu_Pt,weight_SF);

      }
      else if(nbtags==2){
           h_TT_pT_1_2b -> Fill(jet_Pt1,weight_SF);
           h_TT_pT_2_2b -> Fill(jet_Pt2,weight_SF);
           h_TT_pT_3_2b -> Fill(jet_Pt3,weight_SF);
           h_TT_pT_4_2b -> Fill(jet_Pt4,weight_SF);
           h_TT_pT_mu_2b -> Fill(Mu_Pt,weight_SF);

      }
      else if(nbtags>=3){
           h_TT_pT_1_3b -> Fill(jet_Pt1,weight_SF);
           h_TT_pT_2_3b -> Fill(jet_Pt2,weight_SF);
           h_TT_pT_3_3b -> Fill(jet_Pt3,weight_SF);
           h_TT_pT_4_3b -> Fill(jet_Pt4,weight_SF);
           h_TT_pT_mu_3b -> Fill(Mu_Pt,weight_SF);

      }

   }
   }

   for (int i=1; i<3; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv<20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale; //*Trigger_SF*Muon_SF*(MuonISO_SF_UP+MuonISO_SF_DOWN)/2
      if(nbtags==1){
           h_VJ_pT_1_1b -> Fill(jet_Pt1,weight_SF);
           h_VJ_pT_2_1b -> Fill(jet_Pt2,weight_SF);
           h_VJ_pT_3_1b -> Fill(jet_Pt3,weight_SF);
           h_VJ_pT_4_1b -> Fill(jet_Pt4,weight_SF);
           h_VJ_pT_mu_1b -> Fill(Mu_Pt,weight_SF);

      }
      else if(nbtags==2){
           h_VJ_pT_1_2b -> Fill(jet_Pt1,weight_SF);
           h_VJ_pT_2_2b -> Fill(jet_Pt2,weight_SF);
           h_VJ_pT_3_2b -> Fill(jet_Pt3,weight_SF);
           h_VJ_pT_4_2b -> Fill(jet_Pt4,weight_SF);
           h_VJ_pT_mu_2b -> Fill(Mu_Pt,weight_SF);
      }
      else if(nbtags>=3){
           h_VJ_pT_1_3b -> Fill(jet_Pt1,weight_SF);
           h_VJ_pT_2_3b -> Fill(jet_Pt2,weight_SF);
           h_VJ_pT_3_3b -> Fill(jet_Pt3,weight_SF);
           h_VJ_pT_4_3b -> Fill(jet_Pt4,weight_SF);
           h_VJ_pT_mu_3b -> Fill(Mu_Pt,weight_SF);
      }

   }
   }


   for (int i=3; i<10; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv<20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale;
      if(nbtags==1){
           h_ST_pT_1_1b -> Fill(jet_Pt1,weight_SF);
           h_ST_pT_2_1b -> Fill(jet_Pt2,weight_SF);
           h_ST_pT_3_1b -> Fill(jet_Pt3,weight_SF);
           h_ST_pT_4_1b -> Fill(jet_Pt4,weight_SF);
           h_ST_pT_mu_1b -> Fill(Mu_Pt,weight_SF);
      }
      else if(nbtags==2){
           h_ST_pT_1_2b -> Fill(jet_Pt1,weight_SF);
           h_ST_pT_2_2b -> Fill(jet_Pt2,weight_SF);
           h_ST_pT_3_2b -> Fill(jet_Pt3,weight_SF);
           h_ST_pT_4_2b -> Fill(jet_Pt4,weight_SF);
           h_ST_pT_mu_2b -> Fill(Mu_Pt,weight_SF);
      }
      else if(nbtags>=3){
           h_ST_pT_1_3b -> Fill(jet_Pt1,weight_SF);
           h_ST_pT_2_3b -> Fill(jet_Pt2,weight_SF);
           h_ST_pT_3_3b -> Fill(jet_Pt3,weight_SF);
           h_ST_pT_4_3b -> Fill(jet_Pt4,weight_SF);
           h_ST_pT_mu_3b -> Fill(Mu_Pt,weight_SF);
      }

   }
   }

   for (int i=10; i<13; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale;
      if(nbtags==1){
           h_VV_pT_1_1b -> Fill(jet_Pt1,weight_SF);
           h_VV_pT_2_1b -> Fill(jet_Pt2,weight_SF);
           h_VV_pT_3_1b -> Fill(jet_Pt3,weight_SF);
           h_VV_pT_4_1b -> Fill(jet_Pt4,weight_SF);
           h_VV_pT_mu_1b -> Fill(Mu_Pt,weight_SF);
      }
      else if(nbtags==2){
           h_VV_pT_1_2b -> Fill(jet_Pt1,weight_SF);
           h_VV_pT_2_2b -> Fill(jet_Pt2,weight_SF);
           h_VV_pT_3_2b -> Fill(jet_Pt3,weight_SF);
           h_VV_pT_4_2b -> Fill(jet_Pt4,weight_SF);
           h_VV_pT_mu_2b -> Fill(Mu_Pt,weight_SF);
      }
      else if(nbtags>=3){
           h_VV_pT_1_3b -> Fill(jet_Pt1,weight_SF);
           h_VV_pT_2_3b -> Fill(jet_Pt2,weight_SF);
           h_VV_pT_3_3b -> Fill(jet_Pt3,weight_SF);
           h_VV_pT_4_3b -> Fill(jet_Pt4,weight_SF);
           h_VV_pT_mu_3b -> Fill(Mu_Pt,weight_SF);
      }

   }
   }


   for (int i=13; i<17; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv<20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale;   // 36.4466098 is not multiplied.
      if(nbtags==1){
           h_TTX_pT_1_1b -> Fill(jet_Pt1,weight_SF);
           h_TTX_pT_2_1b -> Fill(jet_Pt2,weight_SF);
           h_TTX_pT_3_1b -> Fill(jet_Pt3,weight_SF);
           h_TTX_pT_4_1b -> Fill(jet_Pt4,weight_SF);
           h_TTX_pT_mu_1b -> Fill(Mu_Pt,weight_SF);
      }
      else if(nbtags==2){
           h_TTX_pT_1_2b -> Fill(jet_Pt1,weight_SF);
           h_TTX_pT_2_2b -> Fill(jet_Pt2,weight_SF);
           h_TTX_pT_3_2b -> Fill(jet_Pt3,weight_SF);
           h_TTX_pT_4_2b -> Fill(jet_Pt4,weight_SF);
           h_TTX_pT_mu_2b -> Fill(Mu_Pt,weight_SF);
      }
      else if(nbtags>=3){
           h_TTX_pT_1_3b -> Fill(jet_Pt1,weight_SF);
           h_TTX_pT_2_3b -> Fill(jet_Pt2,weight_SF);
           h_TTX_pT_3_3b -> Fill(jet_Pt3,weight_SF);
           h_TTX_pT_4_3b -> Fill(jet_Pt4,weight_SF);
           h_TTX_pT_mu_3b -> Fill(Mu_Pt,weight_SF);
      }

   }
   }



   for (int k=0; k<DATA_t->GetEntries(); k++){
   
      DATA_t->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv<20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut

      if(nbtags==1){
           h_DATA_pT_1_1b -> Fill(jet_Pt1,1.);
           h_DATA_pT_2_1b -> Fill(jet_Pt2,1.);
           h_DATA_pT_3_1b -> Fill(jet_Pt3,1.);
           h_DATA_pT_4_1b -> Fill(jet_Pt4,1.);
           h_DATA_pT_mu_1b -> Fill(Mu_Pt,1.);
      }
      else if(nbtags==2){
           h_DATA_pT_1_2b -> Fill(jet_Pt1,1.);
           h_DATA_pT_2_2b -> Fill(jet_Pt2,1.);
           h_DATA_pT_3_2b -> Fill(jet_Pt3,1.);
           h_DATA_pT_4_2b -> Fill(jet_Pt4,1.);
           h_DATA_pT_mu_2b -> Fill(Mu_Pt,1.);
      }
      else if(nbtags>=3){
           h_DATA_pT_1_3b -> Fill(jet_Pt1,1.);
           h_DATA_pT_2_3b -> Fill(jet_Pt2,1.);
           h_DATA_pT_3_3b -> Fill(jet_Pt3,1.);
           h_DATA_pT_4_3b -> Fill(jet_Pt4,1.);
           h_DATA_pT_mu_3b -> Fill(Mu_Pt,1.);
      }

   }
   

///////////////// QCD ////////////////////
  for (int i=0; i<17; i++){
  for (int k=0; k<MC_antiiso_t[i]->GetEntries(); k++){

     MC_antiiso_t[i]->GetEntry(k);
     if(Mu_Pt<30) continue; /// Muon selection cut
     if(METv <20) continue; /// MET selection cut
     if(jet_Pt1<30) continue; /// Jet selection cut
     if(jet_Pt2<30) continue; /// Jet selection cut
     if(jet_Pt3<30) continue; /// Jet selection cut
     if(jet_Pt4<30) continue; /// Jet selection cut

     double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*QCD_SF_by_eta(Mu_Eta, nbtags)*36.4466098*Scale;               //*36.4466098;
     if(nbtags==1){

	   h_QCD_pT_1_1b -> Fill(jet_Pt1,-weight_SF);
	   h_QCD_pT_2_1b -> Fill(jet_Pt2,-weight_SF);
	   h_QCD_pT_3_1b -> Fill(jet_Pt3,-weight_SF);
	   h_QCD_pT_4_1b -> Fill(jet_Pt4,-weight_SF);
	   h_QCD_pT_mu_1b -> Fill(Mu_Pt,-weight_SF);
     }
     else if(nbtags==2){
	
	   h_QCD_pT_1_2b -> Fill(jet_Pt1,-weight_SF);
	   h_QCD_pT_2_2b -> Fill(jet_Pt2,-weight_SF);
 	   h_QCD_pT_3_2b -> Fill(jet_Pt3,-weight_SF);
	   h_QCD_pT_4_2b -> Fill(jet_Pt4,-weight_SF);
	   h_QCD_pT_mu_2b -> Fill(Mu_Pt,-weight_SF);
     }
     else if(nbtags>=3){
		 	
           h_QCD_pT_1_3b -> Fill(jet_Pt1,-weight_SF);
	   h_QCD_pT_2_3b -> Fill(jet_Pt2,-weight_SF);
 	   h_QCD_pT_3_3b -> Fill(jet_Pt3,-weight_SF);
	   h_QCD_pT_4_3b -> Fill(jet_Pt4,-weight_SF);
	   h_QCD_pT_mu_3b -> Fill(Mu_Pt,-weight_SF);
     }


  }
  }

    for (int k=0; k<DATA_antiiso_t->GetEntries(); k++){

       DATA_antiiso_t->GetEntry(k);
       if(Mu_Pt<30) continue; /// Muon selection cut
       if(METv <20) continue; /// MET selection cut
       if(jet_Pt1<30) continue; /// Jet selection cut
       if(jet_Pt2<30) continue; /// Jet selection cut
       if(jet_Pt3<30) continue; /// Jet selection cut
       if(jet_Pt4<30) continue; /// Jet selection cut

       double weight_SF= QCD_SF_by_eta(Mu_Eta, nbtags);

	 if(nbtags==1){

	    h_QCD_pT_1_1b -> Fill(jet_Pt1,weight_SF);
	    h_QCD_pT_2_1b -> Fill(jet_Pt2,weight_SF);
	    h_QCD_pT_3_1b -> Fill(jet_Pt3,weight_SF);
	    h_QCD_pT_4_1b -> Fill(jet_Pt4,weight_SF);
	    h_QCD_pT_mu_1b -> Fill(Mu_Pt,weight_SF);
         }
	 else if(nbtags==2){
	
            h_QCD_pT_1_2b -> Fill(jet_Pt1,weight_SF);
	    h_QCD_pT_2_2b -> Fill(jet_Pt2,weight_SF);
	    h_QCD_pT_3_2b -> Fill(jet_Pt3,weight_SF);
	    h_QCD_pT_4_2b -> Fill(jet_Pt4,weight_SF);
	    h_QCD_pT_mu_2b -> Fill(Mu_Pt,weight_SF);
	 }
	 else if(nbtags>=3){
	
            h_QCD_pT_1_3b -> Fill(jet_Pt1,weight_SF);
	    h_QCD_pT_2_3b -> Fill(jet_Pt2,weight_SF);
	    h_QCD_pT_3_3b -> Fill(jet_Pt3,weight_SF);
	    h_QCD_pT_4_3b -> Fill(jet_Pt4,weight_SF);
	    h_QCD_pT_mu_3b -> Fill(Mu_Pt,weight_SF);
	 }


    }


//////////////// Stack pT_1 ////////////////////
  THStack *hs_MC_pT_1_1b= new THStack("hs_pT_1_1b","hs_pT_1_1b");
  THStack *hs_MC_pT_1_2b= new THStack("hs_pT_1_2b","hs_pT_1_2b");
  THStack *hs_MC_pT_1_3b= new THStack("hs_pT_1_3b","hs_pT_1_3b");
h_TT_pT_1_1b->SetLineColor(kRed);      h_TT_pT_1_1b->SetFillColor(kRed);
h_TT_pT_1_2b->SetLineColor(kRed);      h_TT_pT_1_2b->SetFillColor(kRed);
h_TT_pT_1_3b->SetLineColor(kRed);      h_TT_pT_1_3b->SetFillColor(kRed);

h_ST_pT_1_1b->SetLineColor(kMagenta);      h_ST_pT_1_1b->SetFillColor(kMagenta);
h_ST_pT_1_2b->SetLineColor(kMagenta);      h_ST_pT_1_2b->SetFillColor(kMagenta);
h_ST_pT_1_3b->SetLineColor(kMagenta);      h_ST_pT_1_3b->SetFillColor(kMagenta);

h_VJ_pT_1_1b->SetLineColor(kOrange);      h_VJ_pT_1_1b->SetFillColor(kOrange);
h_VJ_pT_1_2b->SetLineColor(kOrange);      h_VJ_pT_1_2b->SetFillColor(kOrange);
h_VJ_pT_1_3b->SetLineColor(kOrange);      h_VJ_pT_1_3b->SetFillColor(kOrange);

h_VV_pT_1_1b->SetLineColor(kGreen+1);      h_VV_pT_1_1b->SetFillColor(kGreen+1);
h_VV_pT_1_2b->SetLineColor(kGreen+1);      h_VV_pT_1_2b->SetFillColor(kGreen+1);
h_VV_pT_1_3b->SetLineColor(kGreen+1);      h_VV_pT_1_3b->SetFillColor(kGreen+1);

h_QCD_pT_1_1b->SetLineColor(kCyan);      h_QCD_pT_1_1b->SetFillColor(kCyan);
h_QCD_pT_1_2b->SetLineColor(kCyan);      h_QCD_pT_1_2b->SetFillColor(kCyan);
h_QCD_pT_1_3b->SetLineColor(kCyan);      h_QCD_pT_1_3b->SetFillColor(kCyan);

h_TTX_pT_1_1b->SetLineColor(kYellow);      h_TTX_pT_1_1b->SetFillColor(kYellow);
h_TTX_pT_1_2b->SetLineColor(kYellow);      h_TTX_pT_1_2b->SetFillColor(kYellow);
h_TTX_pT_1_3b->SetLineColor(kYellow);      h_TTX_pT_1_3b->SetFillColor(kYellow);


  hs_MC_pT_1_1b->Add(h_TT_pT_1_1b);
  hs_MC_pT_1_2b->Add(h_TT_pT_1_2b);
  hs_MC_pT_1_3b->Add(h_TT_pT_1_3b);
  hs_MC_pT_1_1b->Add(h_ST_pT_1_1b);
  hs_MC_pT_1_2b->Add(h_ST_pT_1_2b);
  hs_MC_pT_1_3b->Add(h_ST_pT_1_3b);
  hs_MC_pT_1_1b->Add(h_VJ_pT_1_1b);
  hs_MC_pT_1_2b->Add(h_VJ_pT_1_2b);
  hs_MC_pT_1_3b->Add(h_VJ_pT_1_3b);
  hs_MC_pT_1_1b->Add(h_VV_pT_1_1b);
  hs_MC_pT_1_2b->Add(h_VV_pT_1_2b);
  hs_MC_pT_1_3b->Add(h_VV_pT_1_3b);
  hs_MC_pT_1_1b->Add(h_QCD_pT_1_1b);
  hs_MC_pT_1_2b->Add(h_QCD_pT_1_2b);
  hs_MC_pT_1_3b->Add(h_QCD_pT_1_3b);
  hs_MC_pT_1_1b->Add(h_TTX_pT_1_1b);
  hs_MC_pT_1_2b->Add(h_TTX_pT_1_2b);
  hs_MC_pT_1_3b->Add(h_TTX_pT_1_3b);



//MC error

        TH1F *err_hs_MC_pT_1_1b = new TH1F("err_hs_MC_pT_1_1b", "err_hs_MC_pT_1_1b", 60, 0, 300);
        TH1F *err_hs_MC_pT_1_2b = new TH1F("err_hs_MC_pT_1_2b", "err_hs_MC_pT_1_2b", 60, 0, 300);
        TH1F *err_hs_MC_pT_1_3b = new TH1F("err_hs_MC_pT_1_3b", "err_hs_MC_pT_1_3b", 60, 0, 300);



  err_hs_MC_pT_1_1b->Sumw2();
  err_hs_MC_pT_1_2b->Sumw2();
  err_hs_MC_pT_1_3b->Sumw2();


   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;


  err_hs_MC_pT_1_1b->Add(h_TT_pT_1_1b);
  err_hs_MC_pT_1_2b->Add(h_TT_pT_1_2b);
  err_hs_MC_pT_1_3b->Add(h_TT_pT_1_3b);
  err_hs_MC_pT_1_1b->Add(h_ST_pT_1_1b);
  err_hs_MC_pT_1_2b->Add(h_ST_pT_1_2b);
  err_hs_MC_pT_1_3b->Add(h_ST_pT_1_3b);
  err_hs_MC_pT_1_1b->Add(h_VJ_pT_1_1b);
  err_hs_MC_pT_1_2b->Add(h_VJ_pT_1_2b);
  err_hs_MC_pT_1_3b->Add(h_VJ_pT_1_3b);
  err_hs_MC_pT_1_1b->Add(h_VV_pT_1_1b);
  err_hs_MC_pT_1_2b->Add(h_VV_pT_1_2b);
  err_hs_MC_pT_1_3b->Add(h_VV_pT_1_3b);
  err_hs_MC_pT_1_1b->Add(h_QCD_pT_1_1b);
  err_hs_MC_pT_1_2b->Add(h_QCD_pT_1_2b);
  err_hs_MC_pT_1_3b->Add(h_QCD_pT_1_3b);
  err_hs_MC_pT_1_1b->Add(h_TTX_pT_1_1b);
  err_hs_MC_pT_1_2b->Add(h_TTX_pT_1_2b);
  err_hs_MC_pT_1_3b->Add(h_TTX_pT_1_3b);




////////////////////////////////////////////// pT_1 1b ///////////////////////////////////////////////////////////////////


	TCanvas *c1 = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1 = new TPad("","",0,0.4,1,1);
        c1 -> cd();
  pad1->SetBottomMargin(0);
  pad1->Draw();
  pad1->cd();
//  pad1->SetLogy();



	hs_MC_pT_1_1b->Draw("hist");


	err_hs_MC_pT_1_1b->SetFillColor(kGray+2);
	err_hs_MC_pT_1_1b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_1_1b->SetMarkerStyle(1);
	err_hs_MC_pT_1_1b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_1_1b->SetFillStyle(3001);

        err_hs_MC_pT_1_1b->Draw("E2Same");

	//The Labels
  TLegend* legend_pt_1_1b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_1_1b->AddEntry(h_DATA_pT_1_1b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_1_1b->AddEntry(h_ST_pT_1_1b, "Single top", "f");
  legend_pt_1_1b->AddEntry(h_QCD_pT_1_1b, "QCD", "f");
  legend_pt_1_1b->AddEntry(h_VV_pT_1_1b, "VV", "f");

  legend_pt_1_1b->SetFillColor(0);
  legend_pt_1_1b->SetLineColor(0);
  legend_pt_1_1b->SetBorderSize(0);
  legend_pt_1_1b->SetTextFont(42); 
  legend_pt_1_1b->SetTextSize(0.045);              
  legend_pt_1_1b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_1_1b->SetEntrySeparation(0.3);
  legend_pt_1_1b->Draw();

  

  TLegend* legend_pt_1_1b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_1_1b_3->AddEntry(h_TT_pT_1_1b, "t#bar{t}", "f");
  legend_pt_1_1b_3->AddEntry(h_VJ_pT_1_1b, "VJ", "f");
  legend_pt_1_1b_3->AddEntry(h_TTX_pT_1_1b, "t#bar{t}X", "f"); 
  legend_pt_1_1b_3->AddEntry(err_hs_MC_pT_1_1b, "Stat. Error", "f"); 

  legend_pt_1_1b_3->SetFillColor(0);
  legend_pt_1_1b_3->SetLineColor(0);
  legend_pt_1_1b_3->SetBorderSize(0);
  legend_pt_1_1b_3->SetTextFont(42); 
  legend_pt_1_1b_3->SetTextSize(0.045);                                              
  legend_pt_1_1b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_1_1b_3->SetEntrySeparation(0.3);
  legend_pt_1_1b_3->Draw();


	h_DATA_pT_1_1b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_1_1b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_1_1b->Draw("epsame");

				TH1F* pT_1_1b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_1_1b_ratio_MC->Sumw2();

			  TH1F* pT_1_1b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_1_1b_one->Fill(i);
			  }
	 		  pT_1_1b_ratio_MC->Add(h_VV_pT_1_1b);
			  pT_1_1b_ratio_MC->Add(h_QCD_pT_1_1b);
			  pT_1_1b_ratio_MC->Add(h_VJ_pT_1_1b);
			  pT_1_1b_ratio_MC->Add(h_ST_pT_1_1b);
			  pT_1_1b_ratio_MC->Add(h_TT_pT_1_1b);
			  pT_1_1b_ratio_MC->Add(h_TTX_pT_1_1b);




			  c1->cd();
			  TPad *pad11 = new TPad("","",0,0.,1,0.4);
			  pad11->SetTopMargin(1);
			  pad11->Draw();
			  pad11->cd();

			  TH1F *pT_1_ratio_1b_DATA = (TH1F*)h_DATA_pT_1_1b->Clone();
			  pT_1_ratio_1b_DATA->Sumw2();
			  pT_1_ratio_1b_DATA->SetFillColor(15);
			  pT_1_ratio_1b_DATA->SetFillStyle(3002);

			  pT_1_ratio_1b_DATA->SetTitle("");
			  pT_1_ratio_1b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_1_ratio_1b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_1_ratio_1b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_1_ratio_1b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_1_ratio_1b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_1_ratio_1b_DATA->SetMinimum(0.6);
			  pT_1_ratio_1b_DATA->SetMaximum(1.6);
			  pT_1_ratio_1b_DATA->SetStats(0);
			  pT_1_ratio_1b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_1_ratio_1b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_1_ratio_1b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_1_ratio_1b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_1_ratio_1b_DATA->Divide(pT_1_1b_ratio_MC);


			  pT_1_ratio_1b_DATA->Draw("e");

			  pT_1_ratio_1b_DATA->SetMarkerStyle(20);
			  pT_1_ratio_1b_DATA->SetMarkerSize(0.5);
			  pT_1_ratio_1b_DATA->SetMarkerColor(1);
			  pT_1_ratio_1b_DATA->SetLineStyle(1);
			  pT_1_ratio_1b_DATA->Draw("same");
                          pT_1_1b_one->SetLineStyle(1);
	                  pT_1_1b_one->Draw("same");


			// ratio error centered at 1

			TH1F* pT_1_1b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_1_1b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_1_1b_ratio_error->SetBinContent(i, 1);
			        pT_1_1b_ratio_error->SetBinError(i, pT_1_ratio_1b_DATA->GetBinError(i));
			  }

			  pT_1_1b_ratio_error->SetMarkerStyle(1);
			  pT_1_1b_ratio_error->SetFillColor(15);
			  pT_1_1b_ratio_error->SetFillStyle(3002);
			  pT_1_1b_ratio_error->Draw("E2same");

			//
	                  pT_1_1b_one->Draw("same");



     c1->SaveAs("hs_pT_1_1b.png");


////////////////////////////////////////////// pT_1 2b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_2b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_2b = new TPad("","",0,0.4,1,1);
        c1_2b -> cd();
  pad1_2b->SetBottomMargin(0);
  pad1_2b->Draw();
  pad1_2b->cd();
//  pad1->SetLogy();



	hs_MC_pT_1_2b->Draw("hist");


	err_hs_MC_pT_1_2b->SetFillColor(kGray+2);
	err_hs_MC_pT_1_2b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_1_2b->SetMarkerStyle(1);
	err_hs_MC_pT_1_2b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_1_2b->SetFillStyle(3001);

        err_hs_MC_pT_1_2b->Draw("E2Same");

	//The Labels
  TLegend* legend_pt_1_2b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_1_2b->AddEntry(h_DATA_pT_1_2b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_1_2b->AddEntry(h_ST_pT_1_2b, "Single top", "f");
  legend_pt_1_2b->AddEntry(h_QCD_pT_1_2b, "QCD", "f");
  legend_pt_1_2b->AddEntry(h_VV_pT_1_2b, "VV", "f");

  legend_pt_1_2b->SetFillColor(0);
  legend_pt_1_2b->SetLineColor(0);
  legend_pt_1_2b->SetBorderSize(0);
  legend_pt_1_2b->SetTextFont(42); 
  legend_pt_1_2b->SetTextSize(0.045);              
  legend_pt_1_2b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_1_2b->SetEntrySeparation(0.3);
  legend_pt_1_2b->Draw();

  

  TLegend* legend_pt_1_2b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_1_2b_3->AddEntry(h_TT_pT_1_2b, "t#bar{t}", "f");
  legend_pt_1_2b_3->AddEntry(h_VJ_pT_1_2b, "VJ", "f");
  legend_pt_1_2b_3->AddEntry(h_TTX_pT_1_2b, "t#bar{t}X", "f"); 
  legend_pt_1_2b_3->AddEntry(err_hs_MC_pT_1_2b, "Stat. Error", "f"); 

  legend_pt_1_2b_3->SetFillColor(0);
  legend_pt_1_2b_3->SetLineColor(0);
  legend_pt_1_2b_3->SetBorderSize(0);
  legend_pt_1_2b_3->SetTextFont(42); 
  legend_pt_1_2b_3->SetTextSize(0.045);                                              
  legend_pt_1_2b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_1_2b_3->SetEntrySeparation(0.3);
  legend_pt_1_2b_3->Draw();




	h_DATA_pT_1_2b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_1_2b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_1_2b->Draw("epsame");

				TH1F* pT_1_2b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_1_2b_ratio_MC->Sumw2();

			  TH1F* pT_1_2b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_1_2b_one->Fill(i);
			  }
	 		  pT_1_2b_ratio_MC->Add(h_VV_pT_1_2b);
			  pT_1_2b_ratio_MC->Add(h_QCD_pT_1_2b);
			  pT_1_2b_ratio_MC->Add(h_VJ_pT_1_2b);
			  pT_1_2b_ratio_MC->Add(h_ST_pT_1_2b);
			  pT_1_2b_ratio_MC->Add(h_TT_pT_1_2b);
			  pT_1_2b_ratio_MC->Add(h_TTX_pT_1_2b);



			  c1_2b->cd();
			  TPad *pad11_2b = new TPad("","",0,0.,1,0.4);
			  pad11_2b->SetTopMargin(1);
			  pad11_2b->Draw();
			  pad11_2b->cd();

			  TH1F *pT_1_ratio_2b_DATA = (TH1F*)h_DATA_pT_1_2b->Clone();
			  pT_1_ratio_2b_DATA->Sumw2();
			  pT_1_ratio_2b_DATA->SetFillColor(15);
			  pT_1_ratio_2b_DATA->SetFillStyle(3002);

			  pT_1_ratio_2b_DATA->SetTitle("");
			  pT_1_ratio_2b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_1_ratio_2b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_1_ratio_2b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_1_ratio_2b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_1_ratio_2b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_1_ratio_2b_DATA->SetMinimum(0.6);
			  pT_1_ratio_2b_DATA->SetMaximum(1.6);
			  pT_1_ratio_2b_DATA->SetStats(0);
			  pT_1_ratio_2b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_1_ratio_2b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_1_ratio_2b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_1_ratio_2b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_1_ratio_2b_DATA->Divide(pT_1_2b_ratio_MC);


			  pT_1_ratio_2b_DATA->Draw("e");

			  pT_1_ratio_2b_DATA->SetMarkerStyle(20);
			  pT_1_ratio_2b_DATA->SetMarkerSize(0.5);
			  pT_1_ratio_2b_DATA->SetMarkerColor(1);
			  pT_1_ratio_2b_DATA->SetLineStyle(1);
			  pT_1_ratio_2b_DATA->Draw("same");
                          pT_1_2b_one->SetLineStyle(1);
	                  pT_1_2b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_1_2b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_1_2b_ratio_error -> Sumw2();

			  for(int i=1; i< 300; i++){

				pT_1_2b_ratio_error->SetBinContent(i, 1);
			        pT_1_2b_ratio_error->SetBinError(i, pT_1_ratio_2b_DATA->GetBinError(i));
			  }

			  pT_1_2b_ratio_error->SetMarkerStyle(1);
			  pT_1_2b_ratio_error->SetFillColor(15);
			  pT_1_2b_ratio_error->SetFillStyle(3002);
			  pT_1_2b_ratio_error->Draw("E2same");

			//
	                  pT_1_2b_one->Draw("same");



     c1_2b->SaveAs("hs_pT_1_2b.png");


////////////////////////////////////////////// pT_1 3b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_3b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_3b = new TPad("","",0,0.4,1,1);
        c1_3b -> cd();
  pad1_3b->SetBottomMargin(0);
  pad1_3b->Draw();
  pad1_3b->cd();
//  pad1->SetLogy();



	hs_MC_pT_1_3b->Draw("hist");


	err_hs_MC_pT_1_3b->SetFillColor(kGray+2);
	err_hs_MC_pT_1_3b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_1_3b->SetMarkerStyle(1);
	err_hs_MC_pT_1_3b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_1_3b->SetFillStyle(3001);

        err_hs_MC_pT_1_3b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_1_3b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_1_3b->AddEntry(h_DATA_pT_1_3b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_1_3b->AddEntry(h_ST_pT_1_3b, "Single top", "f");
  legend_pt_1_3b->AddEntry(h_QCD_pT_1_3b, "QCD", "f");
  legend_pt_1_3b->AddEntry(h_VV_pT_1_3b, "VV", "f");

  legend_pt_1_3b->SetFillColor(0);
  legend_pt_1_3b->SetLineColor(0);
  legend_pt_1_3b->SetBorderSize(0);
  legend_pt_1_3b->SetTextFont(42); 
  legend_pt_1_3b->SetTextSize(0.045);              
  legend_pt_1_3b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_1_3b->SetEntrySeparation(0.3);
  legend_pt_1_3b->Draw();

  

  TLegend* legend_pt_1_3b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_1_3b_3->AddEntry(h_TT_pT_1_3b, "t#bar{t}", "f");
  legend_pt_1_3b_3->AddEntry(h_VJ_pT_1_3b, "VJ", "f");
  legend_pt_1_3b_3->AddEntry(h_TTX_pT_1_3b, "t#bar{t}X", "f"); 
  legend_pt_1_3b_3->AddEntry(err_hs_MC_pT_1_3b, "Stat. Error", "f"); 

  legend_pt_1_3b_3->SetFillColor(0);
  legend_pt_1_3b_3->SetLineColor(0);
  legend_pt_1_3b_3->SetBorderSize(0);
  legend_pt_1_3b_3->SetTextFont(42); 
  legend_pt_1_3b_3->SetTextSize(0.045);                                              
  legend_pt_1_3b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_1_3b_3->SetEntrySeparation(0.3);
  legend_pt_1_3b_3->Draw();




	h_DATA_pT_1_3b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_1_3b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_1_3b->Draw("epsame");

				TH1F* pT_1_3b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_1_3b_ratio_MC->Sumw2();

			  TH1F* pT_1_3b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_1_3b_one->Fill(i);
			  }
	 		  pT_1_3b_ratio_MC->Add(h_VV_pT_1_3b);
			  pT_1_3b_ratio_MC->Add(h_QCD_pT_1_3b);
			  pT_1_3b_ratio_MC->Add(h_VJ_pT_1_3b);
			  pT_1_3b_ratio_MC->Add(h_ST_pT_1_3b);
			  pT_1_3b_ratio_MC->Add(h_TT_pT_1_3b);
			  pT_1_3b_ratio_MC->Add(h_TTX_pT_1_3b);


//			  pT_1_3b_ratio_MC->Add(h_MC_TTX_0);

			  c1_3b->cd();
			  TPad *pad11_3b = new TPad("","",0,0.,1,0.4);
			  pad11_3b->SetTopMargin(1);
			  pad11_3b->Draw();
			  pad11_3b->cd();

			  TH1F *pT_1_ratio_3b_DATA = (TH1F*)h_DATA_pT_1_3b->Clone();
			  pT_1_ratio_3b_DATA->Sumw2();
			  pT_1_ratio_3b_DATA->SetFillColor(15);
			  pT_1_ratio_3b_DATA->SetFillStyle(3002);

			  pT_1_ratio_3b_DATA->SetTitle("");
			  pT_1_ratio_3b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_1_ratio_3b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_1_ratio_3b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_1_ratio_3b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_1_ratio_3b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_1_ratio_3b_DATA->SetMinimum(0.6);
			  pT_1_ratio_3b_DATA->SetMaximum(1.6);
			  pT_1_ratio_3b_DATA->SetStats(0);
			  pT_1_ratio_3b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_1_ratio_3b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_1_ratio_3b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_1_ratio_3b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_1_ratio_3b_DATA->Divide(pT_1_3b_ratio_MC);


			  pT_1_ratio_3b_DATA->Draw("e");

			  pT_1_ratio_3b_DATA->SetMarkerStyle(20);
			  pT_1_ratio_3b_DATA->SetMarkerSize(0.5);
			  pT_1_ratio_3b_DATA->SetMarkerColor(1);
			  pT_1_ratio_3b_DATA->SetLineStyle(1);
			  pT_1_ratio_3b_DATA->Draw("same");
                          pT_1_3b_one->SetLineStyle(1);
	                  pT_1_3b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_1_3b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_1_3b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_1_3b_ratio_error->SetBinContent(i, 1);
			        pT_1_3b_ratio_error->SetBinError(i, pT_1_ratio_3b_DATA->GetBinError(i));
			  }

			  pT_1_3b_ratio_error->SetMarkerStyle(1);
			  pT_1_3b_ratio_error->SetFillColor(15);
			  pT_1_3b_ratio_error->SetFillStyle(3002);
			  pT_1_3b_ratio_error->Draw("E2same");

			//
	                  pT_1_3b_one->Draw("same");




     c1_3b->SaveAs("hs_pT_1_3b.png");


//////////////// Stack pT_2 ////////////////////
  THStack *hs_MC_pT_2_1b= new THStack("hs_pT_2_1b","hs_pT_2_1b");
  THStack *hs_MC_pT_2_2b= new THStack("hs_pT_2_2b","hs_pT_2_2b");
  THStack *hs_MC_pT_2_3b= new THStack("hs_pT_2_3b","hs_pT_2_3b");
h_TT_pT_2_1b->SetLineColor(kRed);      h_TT_pT_2_1b->SetFillColor(kRed);
h_TT_pT_2_2b->SetLineColor(kRed);      h_TT_pT_2_2b->SetFillColor(kRed);
h_TT_pT_2_3b->SetLineColor(kRed);      h_TT_pT_2_3b->SetFillColor(kRed);

h_ST_pT_2_1b->SetLineColor(kMagenta);      h_ST_pT_2_1b->SetFillColor(kMagenta);
h_ST_pT_2_2b->SetLineColor(kMagenta);      h_ST_pT_2_2b->SetFillColor(kMagenta);
h_ST_pT_2_3b->SetLineColor(kMagenta);      h_ST_pT_2_3b->SetFillColor(kMagenta);

h_VJ_pT_2_1b->SetLineColor(kOrange);      h_VJ_pT_2_1b->SetFillColor(kOrange);
h_VJ_pT_2_2b->SetLineColor(kOrange);      h_VJ_pT_2_2b->SetFillColor(kOrange);
h_VJ_pT_2_3b->SetLineColor(kOrange);      h_VJ_pT_2_3b->SetFillColor(kOrange);

h_VV_pT_2_1b->SetLineColor(kGreen+1);      h_VV_pT_2_1b->SetFillColor(kGreen+1);
h_VV_pT_2_2b->SetLineColor(kGreen+1);      h_VV_pT_2_2b->SetFillColor(kGreen+1);
h_VV_pT_2_3b->SetLineColor(kGreen+1);      h_VV_pT_2_3b->SetFillColor(kGreen+1);

h_QCD_pT_2_1b->SetLineColor(kCyan);      h_QCD_pT_2_1b->SetFillColor(kCyan);
h_QCD_pT_2_2b->SetLineColor(kCyan);      h_QCD_pT_2_2b->SetFillColor(kCyan);
h_QCD_pT_2_3b->SetLineColor(kCyan);      h_QCD_pT_2_3b->SetFillColor(kCyan);

h_TTX_pT_2_1b->SetLineColor(kYellow);      h_TTX_pT_2_1b->SetFillColor(kYellow);
h_TTX_pT_2_2b->SetLineColor(kYellow);      h_TTX_pT_2_2b->SetFillColor(kYellow);
h_TTX_pT_2_3b->SetLineColor(kYellow);      h_TTX_pT_2_3b->SetFillColor(kYellow);


  hs_MC_pT_2_1b->Add(h_TT_pT_2_1b);
  hs_MC_pT_2_2b->Add(h_TT_pT_2_2b);
  hs_MC_pT_2_3b->Add(h_TT_pT_2_3b);
  hs_MC_pT_2_1b->Add(h_ST_pT_2_1b);
  hs_MC_pT_2_2b->Add(h_ST_pT_2_2b);
  hs_MC_pT_2_3b->Add(h_ST_pT_2_3b);
  hs_MC_pT_2_1b->Add(h_VJ_pT_2_1b);
  hs_MC_pT_2_2b->Add(h_VJ_pT_2_2b);
  hs_MC_pT_2_3b->Add(h_VJ_pT_2_3b);
  hs_MC_pT_2_1b->Add(h_VV_pT_2_1b);
  hs_MC_pT_2_2b->Add(h_VV_pT_2_2b);
  hs_MC_pT_2_3b->Add(h_VV_pT_2_3b);
  hs_MC_pT_2_1b->Add(h_QCD_pT_2_1b);
  hs_MC_pT_2_2b->Add(h_QCD_pT_2_2b);
  hs_MC_pT_2_3b->Add(h_QCD_pT_2_3b);
  hs_MC_pT_2_1b->Add(h_TTX_pT_2_1b);
  hs_MC_pT_2_2b->Add(h_TTX_pT_2_2b);
  hs_MC_pT_2_3b->Add(h_TTX_pT_2_3b);



//MC error

        TH1F *err_hs_MC_pT_2_1b = new TH1F("err_hs_MC_pT_2_1b", "err_hs_MC_pT_2_1b", 60, 0, 300);
        TH1F *err_hs_MC_pT_2_2b = new TH1F("err_hs_MC_pT_2_2b", "err_hs_MC_pT_2_2b", 60, 0, 300);
        TH1F *err_hs_MC_pT_2_3b = new TH1F("err_hs_MC_pT_2_3b", "err_hs_MC_pT_2_3b", 60, 0, 300);



  err_hs_MC_pT_2_1b->Sumw2();
  err_hs_MC_pT_2_2b->Sumw2();
  err_hs_MC_pT_2_3b->Sumw2();


   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;


  err_hs_MC_pT_2_1b->Add(h_TT_pT_2_1b);
  err_hs_MC_pT_2_2b->Add(h_TT_pT_2_2b);
  err_hs_MC_pT_2_3b->Add(h_TT_pT_2_3b);
  err_hs_MC_pT_2_1b->Add(h_ST_pT_2_1b);
  err_hs_MC_pT_2_2b->Add(h_ST_pT_2_2b);
  err_hs_MC_pT_2_3b->Add(h_ST_pT_2_3b);
  err_hs_MC_pT_2_1b->Add(h_VJ_pT_2_1b);
  err_hs_MC_pT_2_2b->Add(h_VJ_pT_2_2b);
  err_hs_MC_pT_2_3b->Add(h_VJ_pT_2_3b);
  err_hs_MC_pT_2_1b->Add(h_VV_pT_2_1b);
  err_hs_MC_pT_2_2b->Add(h_VV_pT_2_2b);
  err_hs_MC_pT_2_3b->Add(h_VV_pT_2_3b);
  err_hs_MC_pT_2_1b->Add(h_QCD_pT_2_1b);
  err_hs_MC_pT_2_2b->Add(h_QCD_pT_2_2b);
  err_hs_MC_pT_2_3b->Add(h_QCD_pT_2_3b);
  err_hs_MC_pT_2_1b->Add(h_TTX_pT_2_1b);
  err_hs_MC_pT_2_2b->Add(h_TTX_pT_2_2b);
  err_hs_MC_pT_2_3b->Add(h_TTX_pT_2_3b);




////////////////////////////////////////////// pT_2 1b ///////////////////////////////////////////////////////////////////


	TCanvas *c1 = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1 = new TPad("","",0,0.4,1,1);
        c1 -> cd();
  pad1->SetBottomMargin(0);
  pad1->Draw();
  pad1->cd();
//  pad1->SetLogy();



	hs_MC_pT_2_1b->Draw("hist");


	err_hs_MC_pT_2_1b->SetFillColor(kGray+2);
	err_hs_MC_pT_2_1b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_2_1b->SetMarkerStyle(1);
	err_hs_MC_pT_2_1b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_2_1b->SetFillStyle(3001);

        err_hs_MC_pT_2_1b->Draw("E2Same");

	//The Labels
  TLegend* legend_pt_2_1b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_2_1b->AddEntry(h_DATA_pT_2_1b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_2_1b->AddEntry(h_ST_pT_2_1b, "Single top", "f");
  legend_pt_2_1b->AddEntry(h_QCD_pT_2_1b, "QCD", "f");
  legend_pt_2_1b->AddEntry(h_VV_pT_2_1b, "VV", "f");

  legend_pt_2_1b->SetFillColor(0);
  legend_pt_2_1b->SetLineColor(0);
  legend_pt_2_1b->SetBorderSize(0);
  legend_pt_2_1b->SetTextFont(42); 
  legend_pt_2_1b->SetTextSize(0.045);              
  legend_pt_2_1b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_2_1b->SetEntrySeparation(0.3);
  legend_pt_2_1b->Draw();

  

  TLegend* legend_pt_2_1b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_2_1b_3->AddEntry(h_TT_pT_2_1b, "t#bar{t}", "f");
  legend_pt_2_1b_3->AddEntry(h_VJ_pT_2_1b, "VJ", "f");
  legend_pt_2_1b_3->AddEntry(h_TTX_pT_2_1b, "t#bar{t}X", "f"); 
  legend_pt_2_1b_3->AddEntry(err_hs_MC_pT_2_1b, "Stat. Error", "f"); 

  legend_pt_2_1b_3->SetFillColor(0);
  legend_pt_2_1b_3->SetLineColor(0);
  legend_pt_2_1b_3->SetBorderSize(0);
  legend_pt_2_1b_3->SetTextFont(42); 
  legend_pt_2_1b_3->SetTextSize(0.045);                                              
  legend_pt_2_1b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_2_1b_3->SetEntrySeparation(0.3);
  legend_pt_2_1b_3->Draw();


	h_DATA_pT_2_1b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_2_1b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_2_1b->Draw("epsame");

				TH1F* pT_2_1b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_2_1b_ratio_MC->Sumw2();

			  TH1F* pT_2_1b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_2_1b_one->Fill(i);
			  }
	 		  pT_2_1b_ratio_MC->Add(h_VV_pT_2_1b);
			  pT_2_1b_ratio_MC->Add(h_QCD_pT_2_1b);
			  pT_2_1b_ratio_MC->Add(h_VJ_pT_2_1b);
			  pT_2_1b_ratio_MC->Add(h_ST_pT_2_1b);
			  pT_2_1b_ratio_MC->Add(h_TT_pT_2_1b);
			  pT_2_1b_ratio_MC->Add(h_TTX_pT_2_1b);




			  c1->cd();
			  TPad *pad11 = new TPad("","",0,0.,1,0.4);
			  pad11->SetTopMargin(1);
			  pad11->Draw();
			  pad11->cd();

			  TH1F *pT_2_ratio_1b_DATA = (TH1F*)h_DATA_pT_2_1b->Clone();
			  pT_2_ratio_1b_DATA->Sumw2();
			  pT_2_ratio_1b_DATA->SetFillColor(15);
			  pT_2_ratio_1b_DATA->SetFillStyle(3002);

			  pT_2_ratio_1b_DATA->SetTitle("");
			  pT_2_ratio_1b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_2_ratio_1b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_2_ratio_1b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_2_ratio_1b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_2_ratio_1b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_2_ratio_1b_DATA->SetMinimum(0.6);
			  pT_2_ratio_1b_DATA->SetMaximum(1.6);
			  pT_2_ratio_1b_DATA->SetStats(0);
			  pT_2_ratio_1b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_2_ratio_1b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_2_ratio_1b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_2_ratio_1b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_2_ratio_1b_DATA->Divide(pT_2_1b_ratio_MC);


			  pT_2_ratio_1b_DATA->Draw("e");

			  pT_2_ratio_1b_DATA->SetMarkerStyle(20);
			  pT_2_ratio_1b_DATA->SetMarkerSize(0.5);
			  pT_2_ratio_1b_DATA->SetMarkerColor(1);
			  pT_2_ratio_1b_DATA->SetLineStyle(1);
			  pT_2_ratio_1b_DATA->Draw("same");
                          pT_2_1b_one->SetLineStyle(1);
	                  pT_2_1b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_2_1b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_2_1b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_2_1b_ratio_error->SetBinContent(i, 1);
			        pT_2_1b_ratio_error->SetBinError(i, pT_2_ratio_1b_DATA->GetBinError(i));
			  }

			  pT_2_1b_ratio_error->SetMarkerStyle(1);
			  pT_2_1b_ratio_error->SetFillColor(15);
			  pT_2_1b_ratio_error->SetFillStyle(3002);
			  pT_2_1b_ratio_error->Draw("E2same");

			//
	                  pT_2_1b_one->Draw("same");





     c1->SaveAs("hs_pT_2_1b.png");


////////////////////////////////////////////// pT_2 2b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_2b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_2b = new TPad("","",0,0.4,1,1);
        c1_2b -> cd();
  pad1_2b->SetBottomMargin(0);
  pad1_2b->Draw();
  pad1_2b->cd();
//  pad1->SetLogy();



	hs_MC_pT_2_2b->Draw("hist");


	err_hs_MC_pT_2_2b->SetFillColor(kGray+2);
	err_hs_MC_pT_2_2b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_2_2b->SetMarkerStyle(1);
	err_hs_MC_pT_2_2b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_2_2b->SetFillStyle(3001);

        err_hs_MC_pT_2_2b->Draw("E2Same");

	//The Labels
  TLegend* legend_pt_2_2b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_2_2b->AddEntry(h_DATA_pT_2_2b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_2_2b->AddEntry(h_ST_pT_2_2b, "Single top", "f");
  legend_pt_2_2b->AddEntry(h_QCD_pT_2_2b, "QCD", "f");
  legend_pt_2_2b->AddEntry(h_VV_pT_2_2b, "VV", "f");

  legend_pt_2_2b->SetFillColor(0);
  legend_pt_2_2b->SetLineColor(0);
  legend_pt_2_2b->SetBorderSize(0);
  legend_pt_2_2b->SetTextFont(42); 
  legend_pt_2_2b->SetTextSize(0.045);              
  legend_pt_2_2b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_2_2b->SetEntrySeparation(0.3);
  legend_pt_2_2b->Draw();

  

  TLegend* legend_pt_2_2b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_2_2b_3->AddEntry(h_TT_pT_2_2b, "t#bar{t}", "f");
  legend_pt_2_2b_3->AddEntry(h_VJ_pT_2_2b, "VJ", "f");
  legend_pt_2_2b_3->AddEntry(h_TTX_pT_2_2b, "t#bar{t}X", "f"); 
  legend_pt_2_2b_3->AddEntry(err_hs_MC_pT_2_2b, "Stat. Error", "f"); 

  legend_pt_2_2b_3->SetFillColor(0);
  legend_pt_2_2b_3->SetLineColor(0);
  legend_pt_2_2b_3->SetBorderSize(0);
  legend_pt_2_2b_3->SetTextFont(42); 
  legend_pt_2_2b_3->SetTextSize(0.045);                                              
  legend_pt_2_2b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_2_2b_3->SetEntrySeparation(0.3);
  legend_pt_2_2b_3->Draw();


	h_DATA_pT_2_2b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_2_2b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_2_2b->Draw("epsame");

				TH1F* pT_2_2b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_2_2b_ratio_MC->Sumw2();

			  TH1F* pT_2_2b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_2_2b_one->Fill(i);
			  }
	 		  pT_2_2b_ratio_MC->Add(h_VV_pT_2_2b);
			  pT_2_2b_ratio_MC->Add(h_QCD_pT_2_2b);
			  pT_2_2b_ratio_MC->Add(h_VJ_pT_2_2b);
			  pT_2_2b_ratio_MC->Add(h_ST_pT_2_2b);
			  pT_2_2b_ratio_MC->Add(h_TT_pT_2_2b);
			  pT_2_2b_ratio_MC->Add(h_TTX_pT_2_2b);



			  c1_2b->cd();
			  TPad *pad11_2b = new TPad("","",0,0.,1,0.4);
			  pad11_2b->SetTopMargin(1);
			  pad11_2b->Draw();
			  pad11_2b->cd();

			  TH1F *pT_2_ratio_2b_DATA = (TH1F*)h_DATA_pT_2_2b->Clone();
			  pT_2_ratio_2b_DATA->Sumw2();
			  pT_2_ratio_2b_DATA->SetFillColor(15);
			  pT_2_ratio_2b_DATA->SetFillStyle(3002);

			  pT_2_ratio_2b_DATA->SetTitle("");
			  pT_2_ratio_2b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_2_ratio_2b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_2_ratio_2b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_2_ratio_2b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_2_ratio_2b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_2_ratio_2b_DATA->SetMinimum(0.6);
			  pT_2_ratio_2b_DATA->SetMaximum(1.6);
			  pT_2_ratio_2b_DATA->SetStats(0);
			  pT_2_ratio_2b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_2_ratio_2b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_2_ratio_2b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_2_ratio_2b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_2_ratio_2b_DATA->Divide(pT_2_2b_ratio_MC);


			  pT_2_ratio_2b_DATA->Draw("e");

			  pT_2_ratio_2b_DATA->SetMarkerStyle(20);
			  pT_2_ratio_2b_DATA->SetMarkerSize(0.5);
			  pT_2_ratio_2b_DATA->SetMarkerColor(1);
			  pT_2_ratio_2b_DATA->SetLineStyle(1);
			  pT_2_ratio_2b_DATA->Draw("same");
                          pT_2_2b_one->SetLineStyle(1);
	                  pT_2_2b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_2_2b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_2_2b_ratio_error -> Sumw2();

			  for(int i=1; i< 300; i++){

				pT_2_2b_ratio_error->SetBinContent(i, 1);
			        pT_2_2b_ratio_error->SetBinError(i, pT_2_ratio_2b_DATA->GetBinError(i));
			  }

			  pT_2_2b_ratio_error->SetMarkerStyle(1);
			  pT_2_2b_ratio_error->SetFillColor(15);
			  pT_2_2b_ratio_error->SetFillStyle(3002);
			  pT_2_2b_ratio_error->Draw("E2same");

			//
	                  pT_2_2b_one->Draw("same");



     c1_2b->SaveAs("hs_pT_2_2b.png");


////////////////////////////////////////////// pT_2 3b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_3b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_3b = new TPad("","",0,0.4,1,1);
        c1_3b -> cd();
  pad1_3b->SetBottomMargin(0);
  pad1_3b->Draw();
  pad1_3b->cd();
//  pad1->SetLogy();



	hs_MC_pT_2_3b->Draw("hist");


	err_hs_MC_pT_2_3b->SetFillColor(kGray+2);
	err_hs_MC_pT_2_3b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_2_3b->SetMarkerStyle(1);
	err_hs_MC_pT_2_3b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_2_3b->SetFillStyle(3001);

        err_hs_MC_pT_2_3b->Draw("E2Same");

	//The Labels
  TLegend* legend_pt_2_3b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_2_3b->AddEntry(h_DATA_pT_2_3b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_2_3b->AddEntry(h_ST_pT_2_3b, "Single top", "f");
  legend_pt_2_3b->AddEntry(h_QCD_pT_2_3b, "QCD", "f");
  legend_pt_2_3b->AddEntry(h_VV_pT_2_3b, "VV", "f");

  legend_pt_2_3b->SetFillColor(0);
  legend_pt_2_3b->SetLineColor(0);
  legend_pt_2_3b->SetBorderSize(0);
  legend_pt_2_3b->SetTextFont(42); 
  legend_pt_2_3b->SetTextSize(0.045);              
  legend_pt_2_3b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_2_3b->SetEntrySeparation(0.3);
  legend_pt_2_3b->Draw();

  

  TLegend* legend_pt_2_3b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_2_3b_3->AddEntry(h_TT_pT_2_3b, "t#bar{t}", "f");
  legend_pt_2_3b_3->AddEntry(h_VJ_pT_2_3b, "VJ", "f");
  legend_pt_2_3b_3->AddEntry(h_TTX_pT_2_3b, "t#bar{t}X", "f"); 
  legend_pt_2_3b_3->AddEntry(err_hs_MC_pT_2_3b, "Stat. Error", "f"); 

  legend_pt_2_3b_3->SetFillColor(0);
  legend_pt_2_3b_3->SetLineColor(0);
  legend_pt_2_3b_3->SetBorderSize(0);
  legend_pt_2_3b_3->SetTextFont(42); 
  legend_pt_2_3b_3->SetTextSize(0.045);                                              
  legend_pt_2_3b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_2_3b_3->SetEntrySeparation(0.3);
  legend_pt_2_3b_3->Draw();


	h_DATA_pT_2_3b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_2_3b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_2_3b->Draw("epsame");

				TH1F* pT_2_3b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_2_3b_ratio_MC->Sumw2();

			  TH1F* pT_2_3b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_2_3b_one->Fill(i);
			  }
	 		  pT_2_3b_ratio_MC->Add(h_VV_pT_2_3b);
			  pT_2_3b_ratio_MC->Add(h_QCD_pT_2_3b);
			  pT_2_3b_ratio_MC->Add(h_VJ_pT_2_3b);
			  pT_2_3b_ratio_MC->Add(h_ST_pT_2_3b);
			  pT_2_3b_ratio_MC->Add(h_TT_pT_2_3b);
			  pT_2_3b_ratio_MC->Add(h_TTX_pT_2_3b);


//			  pT_2_3b_ratio_MC->Add(h_MC_TTX_0);

			  c1_3b->cd();
			  TPad *pad11_3b = new TPad("","",0,0.,1,0.4);
			  pad11_3b->SetTopMargin(1);
			  pad11_3b->Draw();
			  pad11_3b->cd();

			  TH1F *pT_2_ratio_3b_DATA = (TH1F*)h_DATA_pT_2_3b->Clone();
			  pT_2_ratio_3b_DATA->Sumw2();
			  pT_2_ratio_3b_DATA->SetFillColor(15);
			  pT_2_ratio_3b_DATA->SetFillStyle(3002);

			  pT_2_ratio_3b_DATA->SetTitle("");
			  pT_2_ratio_3b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_2_ratio_3b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_2_ratio_3b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_2_ratio_3b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_2_ratio_3b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_2_ratio_3b_DATA->SetMinimum(0.6);
			  pT_2_ratio_3b_DATA->SetMaximum(1.6);
			  pT_2_ratio_3b_DATA->SetStats(0);
			  pT_2_ratio_3b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_2_ratio_3b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_2_ratio_3b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_2_ratio_3b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_2_ratio_3b_DATA->Divide(pT_2_3b_ratio_MC);


			  pT_2_ratio_3b_DATA->Draw("e");

			  pT_2_ratio_3b_DATA->SetMarkerStyle(20);
			  pT_2_ratio_3b_DATA->SetMarkerSize(0.5);
			  pT_2_ratio_3b_DATA->SetMarkerColor(1);
			  pT_2_ratio_3b_DATA->SetLineStyle(1);
			  pT_2_ratio_3b_DATA->Draw("same");
                          pT_2_3b_one->SetLineStyle(1);
	                  pT_2_3b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_2_3b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_2_3b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_2_3b_ratio_error->SetBinContent(i, 1);
			        pT_2_3b_ratio_error->SetBinError(i, pT_2_ratio_3b_DATA->GetBinError(i));
			  }

			  pT_2_3b_ratio_error->SetMarkerStyle(1);
			  pT_2_3b_ratio_error->SetFillColor(15);
			  pT_2_3b_ratio_error->SetFillStyle(3002);
			  pT_2_3b_ratio_error->Draw("E2same");

			//
	                  pT_2_3b_one->Draw("same");




     c1_3b->SaveAs("hs_pT_2_3b.png");

//////////////// Stack pT_3 ////////////////////
  THStack *hs_MC_pT_3_1b= new THStack("hs_pT_3_1b","hs_pT_3_1b");
  THStack *hs_MC_pT_3_2b= new THStack("hs_pT_3_2b","hs_pT_3_2b");
  THStack *hs_MC_pT_3_3b= new THStack("hs_pT_3_3b","hs_pT_3_3b");
h_TT_pT_3_1b->SetLineColor(kRed);      h_TT_pT_3_1b->SetFillColor(kRed);
h_TT_pT_3_2b->SetLineColor(kRed);      h_TT_pT_3_2b->SetFillColor(kRed);
h_TT_pT_3_3b->SetLineColor(kRed);      h_TT_pT_3_3b->SetFillColor(kRed);

h_ST_pT_3_1b->SetLineColor(kMagenta);      h_ST_pT_3_1b->SetFillColor(kMagenta);
h_ST_pT_3_2b->SetLineColor(kMagenta);      h_ST_pT_3_2b->SetFillColor(kMagenta);
h_ST_pT_3_3b->SetLineColor(kMagenta);      h_ST_pT_3_3b->SetFillColor(kMagenta);

h_VJ_pT_3_1b->SetLineColor(kOrange);      h_VJ_pT_3_1b->SetFillColor(kOrange);
h_VJ_pT_3_2b->SetLineColor(kOrange);      h_VJ_pT_3_2b->SetFillColor(kOrange);
h_VJ_pT_3_3b->SetLineColor(kOrange);      h_VJ_pT_3_3b->SetFillColor(kOrange);

h_VV_pT_3_1b->SetLineColor(kGreen+1);      h_VV_pT_3_1b->SetFillColor(kGreen+1);
h_VV_pT_3_2b->SetLineColor(kGreen+1);      h_VV_pT_3_2b->SetFillColor(kGreen+1);
h_VV_pT_3_3b->SetLineColor(kGreen+1);      h_VV_pT_3_3b->SetFillColor(kGreen+1);

h_QCD_pT_3_1b->SetLineColor(kCyan);      h_QCD_pT_3_1b->SetFillColor(kCyan);
h_QCD_pT_3_2b->SetLineColor(kCyan);      h_QCD_pT_3_2b->SetFillColor(kCyan);
h_QCD_pT_3_3b->SetLineColor(kCyan);      h_QCD_pT_3_3b->SetFillColor(kCyan);

h_TTX_pT_3_1b->SetLineColor(kYellow);      h_TTX_pT_3_1b->SetFillColor(kYellow);
h_TTX_pT_3_2b->SetLineColor(kYellow);      h_TTX_pT_3_2b->SetFillColor(kYellow);
h_TTX_pT_3_3b->SetLineColor(kYellow);      h_TTX_pT_3_3b->SetFillColor(kYellow);


  hs_MC_pT_3_1b->Add(h_TT_pT_3_1b);
  hs_MC_pT_3_2b->Add(h_TT_pT_3_2b);
  hs_MC_pT_3_3b->Add(h_TT_pT_3_3b);
  hs_MC_pT_3_1b->Add(h_ST_pT_3_1b);
  hs_MC_pT_3_2b->Add(h_ST_pT_3_2b);
  hs_MC_pT_3_3b->Add(h_ST_pT_3_3b);
  hs_MC_pT_3_1b->Add(h_VJ_pT_3_1b);
  hs_MC_pT_3_2b->Add(h_VJ_pT_3_2b);
  hs_MC_pT_3_3b->Add(h_VJ_pT_3_3b);
  hs_MC_pT_3_1b->Add(h_VV_pT_3_1b);
  hs_MC_pT_3_2b->Add(h_VV_pT_3_2b);
  hs_MC_pT_3_3b->Add(h_VV_pT_3_3b);
  hs_MC_pT_3_1b->Add(h_QCD_pT_3_1b);
  hs_MC_pT_3_2b->Add(h_QCD_pT_3_2b);
  hs_MC_pT_3_3b->Add(h_QCD_pT_3_3b);
  hs_MC_pT_3_1b->Add(h_TTX_pT_3_1b);
  hs_MC_pT_3_2b->Add(h_TTX_pT_3_2b);
  hs_MC_pT_3_3b->Add(h_TTX_pT_3_3b);



//MC error

        TH1F *err_hs_MC_pT_3_1b = new TH1F("err_hs_MC_pT_3_1b", "err_hs_MC_pT_3_1b", 60, 0, 300);
        TH1F *err_hs_MC_pT_3_2b = new TH1F("err_hs_MC_pT_3_2b", "err_hs_MC_pT_3_2b", 60, 0, 300);
        TH1F *err_hs_MC_pT_3_3b = new TH1F("err_hs_MC_pT_3_3b", "err_hs_MC_pT_3_3b", 60, 0, 300);



  err_hs_MC_pT_3_1b->Sumw2();
  err_hs_MC_pT_3_2b->Sumw2();
  err_hs_MC_pT_3_3b->Sumw2();


   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;


  err_hs_MC_pT_3_1b->Add(h_TT_pT_3_1b);
  err_hs_MC_pT_3_2b->Add(h_TT_pT_3_2b);
  err_hs_MC_pT_3_3b->Add(h_TT_pT_3_3b);
  err_hs_MC_pT_3_1b->Add(h_ST_pT_3_1b);
  err_hs_MC_pT_3_2b->Add(h_ST_pT_3_2b);
  err_hs_MC_pT_3_3b->Add(h_ST_pT_3_3b);
  err_hs_MC_pT_3_1b->Add(h_VJ_pT_3_1b);
  err_hs_MC_pT_3_2b->Add(h_VJ_pT_3_2b);
  err_hs_MC_pT_3_3b->Add(h_VJ_pT_3_3b);
  err_hs_MC_pT_3_1b->Add(h_VV_pT_3_1b);
  err_hs_MC_pT_3_2b->Add(h_VV_pT_3_2b);
  err_hs_MC_pT_3_3b->Add(h_VV_pT_3_3b);
  err_hs_MC_pT_3_1b->Add(h_QCD_pT_3_1b);
  err_hs_MC_pT_3_2b->Add(h_QCD_pT_3_2b);
  err_hs_MC_pT_3_3b->Add(h_QCD_pT_3_3b);
  err_hs_MC_pT_3_1b->Add(h_TTX_pT_3_1b);
  err_hs_MC_pT_3_2b->Add(h_TTX_pT_3_2b);
  err_hs_MC_pT_3_3b->Add(h_TTX_pT_3_3b);




////////////////////////////////////////////// pT_3 1b ///////////////////////////////////////////////////////////////////


	TCanvas *c1 = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1 = new TPad("","",0,0.4,1,1);
        c1 -> cd();
  pad1->SetBottomMargin(0);
  pad1->Draw();
  pad1->cd();
//  pad1->SetLogy();



	hs_MC_pT_3_1b->Draw("hist");


	err_hs_MC_pT_3_1b->SetFillColor(kGray+2);
	err_hs_MC_pT_3_1b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_3_1b->SetMarkerStyle(1);
	err_hs_MC_pT_3_1b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_3_1b->SetFillStyle(3001);

        err_hs_MC_pT_3_1b->Draw("E2Same");

	//The Labels
  TLegend* legend_pt_3_1b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_3_1b->AddEntry(h_DATA_pT_3_1b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_3_1b->AddEntry(h_ST_pT_3_1b, "Single top", "f");
  legend_pt_3_1b->AddEntry(h_QCD_pT_3_1b, "QCD", "f");
  legend_pt_3_1b->AddEntry(h_VV_pT_3_1b, "VV", "f");

  legend_pt_3_1b->SetFillColor(0);
  legend_pt_3_1b->SetLineColor(0);
  legend_pt_3_1b->SetBorderSize(0);
  legend_pt_3_1b->SetTextFont(42); 
  legend_pt_3_1b->SetTextSize(0.045);              
  legend_pt_3_1b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_3_1b->SetEntrySeparation(0.3);
  legend_pt_3_1b->Draw();

  

  TLegend* legend_pt_3_1b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_3_1b_3->AddEntry(h_TT_pT_3_1b, "t#bar{t}", "f");
  legend_pt_3_1b_3->AddEntry(h_VJ_pT_3_1b, "VJ", "f");
  legend_pt_3_1b_3->AddEntry(h_TTX_pT_3_1b, "t#bar{t}X", "f"); 
  legend_pt_3_1b_3->AddEntry(err_hs_MC_pT_3_1b, "Stat. Error", "f"); 

  legend_pt_3_1b_3->SetFillColor(0);
  legend_pt_3_1b_3->SetLineColor(0);
  legend_pt_3_1b_3->SetBorderSize(0);
  legend_pt_3_1b_3->SetTextFont(42); 
  legend_pt_3_1b_3->SetTextSize(0.045);                                              
  legend_pt_3_1b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_3_1b_3->SetEntrySeparation(0.3);
  legend_pt_3_1b_3->Draw();


	h_DATA_pT_3_1b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_3_1b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_3_1b->Draw("epsame");

				TH1F* pT_3_1b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_3_1b_ratio_MC->Sumw2();

			  TH1F* pT_3_1b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_3_1b_one->Fill(i);
			  }
	 		  pT_3_1b_ratio_MC->Add(h_VV_pT_3_1b);
			  pT_3_1b_ratio_MC->Add(h_QCD_pT_3_1b);
			  pT_3_1b_ratio_MC->Add(h_VJ_pT_3_1b);
			  pT_3_1b_ratio_MC->Add(h_ST_pT_3_1b);
			  pT_3_1b_ratio_MC->Add(h_TT_pT_3_1b);
			  pT_3_1b_ratio_MC->Add(h_TTX_pT_3_1b);




			  c1->cd();
			  TPad *pad11 = new TPad("","",0,0.,1,0.4);
			  pad11->SetTopMargin(1);
			  pad11->Draw();
			  pad11->cd();

			  TH1F *pT_3_ratio_1b_DATA = (TH1F*)h_DATA_pT_3_1b->Clone();
			  pT_3_ratio_1b_DATA->Sumw2();
			  pT_3_ratio_1b_DATA->SetFillColor(15);
			  pT_3_ratio_1b_DATA->SetFillStyle(3002);

			  pT_3_ratio_1b_DATA->SetTitle("");
			  pT_3_ratio_1b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_3_ratio_1b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_3_ratio_1b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_3_ratio_1b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_3_ratio_1b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_3_ratio_1b_DATA->SetMinimum(0.6);
			  pT_3_ratio_1b_DATA->SetMaximum(1.6);
			  pT_3_ratio_1b_DATA->SetStats(0);
			  pT_3_ratio_1b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_3_ratio_1b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_3_ratio_1b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_3_ratio_1b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_3_ratio_1b_DATA->Divide(pT_3_1b_ratio_MC);


			  pT_3_ratio_1b_DATA->Draw("e");

			  pT_3_ratio_1b_DATA->SetMarkerStyle(20);
			  pT_3_ratio_1b_DATA->SetMarkerSize(0.5);
			  pT_3_ratio_1b_DATA->SetMarkerColor(1);
			  pT_3_ratio_1b_DATA->SetLineStyle(1);
			  pT_3_ratio_1b_DATA->Draw("same");
                          pT_3_1b_one->SetLineStyle(1);
	                  pT_3_1b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_3_1b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_3_1b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_3_1b_ratio_error->SetBinContent(i, 1);
			        pT_3_1b_ratio_error->SetBinError(i, pT_3_ratio_1b_DATA->GetBinError(i));
			  }

			  pT_3_1b_ratio_error->SetMarkerStyle(1);
			  pT_3_1b_ratio_error->SetFillColor(15);
			  pT_3_1b_ratio_error->SetFillStyle(3002);
			  pT_3_1b_ratio_error->Draw("E2same");

			//
	                  pT_3_1b_one->Draw("same");



     c1->SaveAs("hs_pT_3_1b.png");


////////////////////////////////////////////// pT_3 2b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_2b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_2b = new TPad("","",0,0.4,1,1);
        c1_2b -> cd();
  pad1_2b->SetBottomMargin(0);
  pad1_2b->Draw();
  pad1_2b->cd();
//  pad1->SetLogy();



	hs_MC_pT_3_2b->Draw("hist");


	err_hs_MC_pT_3_2b->SetFillColor(kGray+2);
	err_hs_MC_pT_3_2b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_3_2b->SetMarkerStyle(1);
	err_hs_MC_pT_3_2b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_3_2b->SetFillStyle(3001);

        err_hs_MC_pT_3_2b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_3_2b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_3_2b->AddEntry(h_DATA_pT_3_2b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_3_2b->AddEntry(h_ST_pT_3_2b, "Single top", "f");
  legend_pt_3_2b->AddEntry(h_QCD_pT_3_2b, "QCD", "f");
  legend_pt_3_2b->AddEntry(h_VV_pT_3_2b, "VV", "f");

  legend_pt_3_2b->SetFillColor(0);
  legend_pt_3_2b->SetLineColor(0);
  legend_pt_3_2b->SetBorderSize(0);
  legend_pt_3_2b->SetTextFont(42); 
  legend_pt_3_2b->SetTextSize(0.045);              
  legend_pt_3_2b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_3_2b->SetEntrySeparation(0.3);
  legend_pt_3_2b->Draw();

  

  TLegend* legend_pt_3_2b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_3_2b_3->AddEntry(h_TT_pT_3_2b, "t#bar{t}", "f");
  legend_pt_3_2b_3->AddEntry(h_VJ_pT_3_2b, "VJ", "f");
  legend_pt_3_2b_3->AddEntry(h_TTX_pT_3_2b, "t#bar{t}X", "f"); 
  legend_pt_3_2b_3->AddEntry(err_hs_MC_pT_3_2b, "Stat. Error", "f"); 

  legend_pt_3_2b_3->SetFillColor(0);
  legend_pt_3_2b_3->SetLineColor(0);
  legend_pt_3_2b_3->SetBorderSize(0);
  legend_pt_3_2b_3->SetTextFont(42); 
  legend_pt_3_2b_3->SetTextSize(0.045);                                              
  legend_pt_3_2b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_3_2b_3->SetEntrySeparation(0.3);
  legend_pt_3_2b_3->Draw();



	h_DATA_pT_3_2b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_3_2b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_3_2b->Draw("epsame");

				TH1F* pT_3_2b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_3_2b_ratio_MC->Sumw2();

			  TH1F* pT_3_2b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_3_2b_one->Fill(i);
			  }
	 		  pT_3_2b_ratio_MC->Add(h_VV_pT_3_2b);
			  pT_3_2b_ratio_MC->Add(h_QCD_pT_3_2b);
			  pT_3_2b_ratio_MC->Add(h_VJ_pT_3_2b);
			  pT_3_2b_ratio_MC->Add(h_ST_pT_3_2b);
			  pT_3_2b_ratio_MC->Add(h_TT_pT_3_2b);
			  pT_3_2b_ratio_MC->Add(h_TTX_pT_3_2b);



			  c1_2b->cd();
			  TPad *pad11_2b = new TPad("","",0,0.,1,0.4);
			  pad11_2b->SetTopMargin(1);
			  pad11_2b->Draw();
			  pad11_2b->cd();

			  TH1F *pT_3_ratio_2b_DATA = (TH1F*)h_DATA_pT_3_2b->Clone();
			  pT_3_ratio_2b_DATA->Sumw2();
			  pT_3_ratio_2b_DATA->SetFillColor(15);
			  pT_3_ratio_2b_DATA->SetFillStyle(3002);

			  pT_3_ratio_2b_DATA->SetTitle("");
			  pT_3_ratio_2b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_3_ratio_2b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_3_ratio_2b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_3_ratio_2b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_3_ratio_2b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_3_ratio_2b_DATA->SetMinimum(0.6);
			  pT_3_ratio_2b_DATA->SetMaximum(1.6);
			  pT_3_ratio_2b_DATA->SetStats(0);
			  pT_3_ratio_2b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_3_ratio_2b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_3_ratio_2b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_3_ratio_2b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_3_ratio_2b_DATA->Divide(pT_3_2b_ratio_MC);


			  pT_3_ratio_2b_DATA->Draw("e");

			  pT_3_ratio_2b_DATA->SetMarkerStyle(20);
			  pT_3_ratio_2b_DATA->SetMarkerSize(0.5);
			  pT_3_ratio_2b_DATA->SetMarkerColor(1);
			  pT_3_ratio_2b_DATA->SetLineStyle(1);
			  pT_3_ratio_2b_DATA->Draw("same");
                          pT_3_2b_one->SetLineStyle(1);
	                  pT_3_2b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_3_2b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_3_2b_ratio_error -> Sumw2();

			  for(int i=1; i< 300; i++){

				pT_3_2b_ratio_error->SetBinContent(i, 1);
			        pT_3_2b_ratio_error->SetBinError(i, pT_3_ratio_2b_DATA->GetBinError(i));
			  }

			  pT_3_2b_ratio_error->SetMarkerStyle(1);
			  pT_3_2b_ratio_error->SetFillColor(15);
			  pT_3_2b_ratio_error->SetFillStyle(3002);
			  pT_3_2b_ratio_error->Draw("E2same");

			//
	                  pT_3_2b_one->Draw("same");



     c1_2b->SaveAs("hs_pT_3_2b.png");


////////////////////////////////////////////// pT_3 3b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_3b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_3b = new TPad("","",0,0.4,1,1);
        c1_3b -> cd();
  pad1_3b->SetBottomMargin(0);
  pad1_3b->Draw();
  pad1_3b->cd();
//  pad1->SetLogy();



	hs_MC_pT_3_3b->Draw("hist");


	err_hs_MC_pT_3_3b->SetFillColor(kGray+2);
	err_hs_MC_pT_3_3b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_3_3b->SetMarkerStyle(1);
	err_hs_MC_pT_3_3b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_3_3b->SetFillStyle(3001);

        err_hs_MC_pT_3_3b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_3_3b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_3_3b->AddEntry(h_DATA_pT_3_3b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_3_3b->AddEntry(h_ST_pT_3_3b, "Single top", "f");
  legend_pt_3_3b->AddEntry(h_QCD_pT_3_3b, "QCD", "f");
  legend_pt_3_3b->AddEntry(h_VV_pT_3_3b, "VV", "f");

  legend_pt_3_3b->SetFillColor(0);
  legend_pt_3_3b->SetLineColor(0);
  legend_pt_3_3b->SetBorderSize(0);
  legend_pt_3_3b->SetTextFont(42); 
  legend_pt_3_3b->SetTextSize(0.045);              
  legend_pt_3_3b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_3_3b->SetEntrySeparation(0.3);
  legend_pt_3_3b->Draw();

  

  TLegend* legend_pt_3_3b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_3_3b_3->AddEntry(h_TT_pT_3_3b, "t#bar{t}", "f");
  legend_pt_3_3b_3->AddEntry(h_VJ_pT_3_3b, "VJ", "f");
  legend_pt_3_3b_3->AddEntry(h_TTX_pT_3_3b, "t#bar{t}X", "f"); 
  legend_pt_3_3b_3->AddEntry(err_hs_MC_pT_3_3b, "Stat. Error", "f"); 

  legend_pt_3_3b_3->SetFillColor(0);
  legend_pt_3_3b_3->SetLineColor(0);
  legend_pt_3_3b_3->SetBorderSize(0);
  legend_pt_3_3b_3->SetTextFont(42); 
  legend_pt_3_3b_3->SetTextSize(0.045);                                              
  legend_pt_3_3b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_3_3b_3->SetEntrySeparation(0.3);
  legend_pt_3_3b_3->Draw();

	h_DATA_pT_3_3b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_3_3b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_3_3b->Draw("epsame");

				TH1F* pT_3_3b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_3_3b_ratio_MC->Sumw2();

			  TH1F* pT_3_3b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_3_3b_one->Fill(i);
			  }
	 		  pT_3_3b_ratio_MC->Add(h_VV_pT_3_3b);
			  pT_3_3b_ratio_MC->Add(h_QCD_pT_3_3b);
			  pT_3_3b_ratio_MC->Add(h_VJ_pT_3_3b);
			  pT_3_3b_ratio_MC->Add(h_ST_pT_3_3b);
			  pT_3_3b_ratio_MC->Add(h_TT_pT_3_3b);
			  pT_3_3b_ratio_MC->Add(h_TTX_pT_3_3b);


//			  pT_3_3b_ratio_MC->Add(h_MC_TTX_0);

			  c1_3b->cd();
			  TPad *pad11_3b = new TPad("","",0,0.,1,0.4);
			  pad11_3b->SetTopMargin(1);
			  pad11_3b->Draw();
			  pad11_3b->cd();

			  TH1F *pT_3_ratio_3b_DATA = (TH1F*)h_DATA_pT_3_3b->Clone();
			  pT_3_ratio_3b_DATA->Sumw2();
			  pT_3_ratio_3b_DATA->SetFillColor(15);
			  pT_3_ratio_3b_DATA->SetFillStyle(3002);

			  pT_3_ratio_3b_DATA->SetTitle("");
			  pT_3_ratio_3b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_3_ratio_3b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_3_ratio_3b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_3_ratio_3b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_3_ratio_3b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_3_ratio_3b_DATA->SetMinimum(0.6);
			  pT_3_ratio_3b_DATA->SetMaximum(1.6);
			  pT_3_ratio_3b_DATA->SetStats(0);
			  pT_3_ratio_3b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_3_ratio_3b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_3_ratio_3b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_3_ratio_3b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_3_ratio_3b_DATA->Divide(pT_3_3b_ratio_MC);


			  pT_3_ratio_3b_DATA->Draw("e");

			  pT_3_ratio_3b_DATA->SetMarkerStyle(20);
			  pT_3_ratio_3b_DATA->SetMarkerSize(0.5);
			  pT_3_ratio_3b_DATA->SetMarkerColor(1);
			  pT_3_ratio_3b_DATA->SetLineStyle(1);
			  pT_3_ratio_3b_DATA->Draw("same");
                          pT_3_3b_one->SetLineStyle(1);
	                  pT_3_3b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_3_3b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_3_3b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_3_3b_ratio_error->SetBinContent(i, 1);
			        pT_3_3b_ratio_error->SetBinError(i, pT_3_ratio_3b_DATA->GetBinError(i));
			  }

			  pT_3_3b_ratio_error->SetMarkerStyle(1);
			  pT_3_3b_ratio_error->SetFillColor(15);
			  pT_3_3b_ratio_error->SetFillStyle(3002);
			  pT_3_3b_ratio_error->Draw("E2same");

			//
	                  pT_3_3b_one->Draw("same");



     c1_3b->SaveAs("hs_pT_3_3b.png");

//////////////// Stack pT_4 ////////////////////
  THStack *hs_MC_pT_4_1b= new THStack("hs_pT_4_1b","hs_pT_4_1b");
  THStack *hs_MC_pT_4_2b= new THStack("hs_pT_4_2b","hs_pT_4_2b");
  THStack *hs_MC_pT_4_3b= new THStack("hs_pT_4_3b","hs_pT_4_3b");
h_TT_pT_4_1b->SetLineColor(kRed);      h_TT_pT_4_1b->SetFillColor(kRed);
h_TT_pT_4_2b->SetLineColor(kRed);      h_TT_pT_4_2b->SetFillColor(kRed);
h_TT_pT_4_3b->SetLineColor(kRed);      h_TT_pT_4_3b->SetFillColor(kRed);

h_ST_pT_4_1b->SetLineColor(kMagenta);      h_ST_pT_4_1b->SetFillColor(kMagenta);
h_ST_pT_4_2b->SetLineColor(kMagenta);      h_ST_pT_4_2b->SetFillColor(kMagenta);
h_ST_pT_4_3b->SetLineColor(kMagenta);      h_ST_pT_4_3b->SetFillColor(kMagenta);

h_VJ_pT_4_1b->SetLineColor(kOrange);      h_VJ_pT_4_1b->SetFillColor(kOrange);
h_VJ_pT_4_2b->SetLineColor(kOrange);      h_VJ_pT_4_2b->SetFillColor(kOrange);
h_VJ_pT_4_3b->SetLineColor(kOrange);      h_VJ_pT_4_3b->SetFillColor(kOrange);

h_VV_pT_4_1b->SetLineColor(kGreen+1);      h_VV_pT_4_1b->SetFillColor(kGreen+1);
h_VV_pT_4_2b->SetLineColor(kGreen+1);      h_VV_pT_4_2b->SetFillColor(kGreen+1);
h_VV_pT_4_3b->SetLineColor(kGreen+1);      h_VV_pT_4_3b->SetFillColor(kGreen+1);

h_QCD_pT_4_1b->SetLineColor(kCyan);      h_QCD_pT_4_1b->SetFillColor(kCyan);
h_QCD_pT_4_2b->SetLineColor(kCyan);      h_QCD_pT_4_2b->SetFillColor(kCyan);
h_QCD_pT_4_3b->SetLineColor(kCyan);      h_QCD_pT_4_3b->SetFillColor(kCyan);

h_TTX_pT_4_1b->SetLineColor(kYellow);      h_TTX_pT_4_1b->SetFillColor(kYellow);
h_TTX_pT_4_2b->SetLineColor(kYellow);      h_TTX_pT_4_2b->SetFillColor(kYellow);
h_TTX_pT_4_3b->SetLineColor(kYellow);      h_TTX_pT_4_3b->SetFillColor(kYellow);


  hs_MC_pT_4_1b->Add(h_TT_pT_4_1b);
  hs_MC_pT_4_2b->Add(h_TT_pT_4_2b);
  hs_MC_pT_4_3b->Add(h_TT_pT_4_3b);
  hs_MC_pT_4_1b->Add(h_ST_pT_4_1b);
  hs_MC_pT_4_2b->Add(h_ST_pT_4_2b);
  hs_MC_pT_4_3b->Add(h_ST_pT_4_3b);
  hs_MC_pT_4_1b->Add(h_VJ_pT_4_1b);
  hs_MC_pT_4_2b->Add(h_VJ_pT_4_2b);
  hs_MC_pT_4_3b->Add(h_VJ_pT_4_3b);
  hs_MC_pT_4_1b->Add(h_VV_pT_4_1b);
  hs_MC_pT_4_2b->Add(h_VV_pT_4_2b);
  hs_MC_pT_4_3b->Add(h_VV_pT_4_3b);
  hs_MC_pT_4_1b->Add(h_QCD_pT_4_1b);
  hs_MC_pT_4_2b->Add(h_QCD_pT_4_2b);
  hs_MC_pT_4_3b->Add(h_QCD_pT_4_3b);
  hs_MC_pT_4_1b->Add(h_TTX_pT_4_1b);
  hs_MC_pT_4_2b->Add(h_TTX_pT_4_2b);
  hs_MC_pT_4_3b->Add(h_TTX_pT_4_3b);



//MC error

        TH1F *err_hs_MC_pT_4_1b = new TH1F("err_hs_MC_pT_4_1b", "err_hs_MC_pT_4_1b", 60, 0, 300);
        TH1F *err_hs_MC_pT_4_2b = new TH1F("err_hs_MC_pT_4_2b", "err_hs_MC_pT_4_2b", 60, 0, 300);
        TH1F *err_hs_MC_pT_4_3b = new TH1F("err_hs_MC_pT_4_3b", "err_hs_MC_pT_4_3b", 60, 0, 300);



  err_hs_MC_pT_4_1b->Sumw2();
  err_hs_MC_pT_4_2b->Sumw2();
  err_hs_MC_pT_4_3b->Sumw2();


   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;


  err_hs_MC_pT_4_1b->Add(h_TT_pT_4_1b);
  err_hs_MC_pT_4_2b->Add(h_TT_pT_4_2b);
  err_hs_MC_pT_4_3b->Add(h_TT_pT_4_3b);
  err_hs_MC_pT_4_1b->Add(h_ST_pT_4_1b);
  err_hs_MC_pT_4_2b->Add(h_ST_pT_4_2b);
  err_hs_MC_pT_4_3b->Add(h_ST_pT_4_3b);
  err_hs_MC_pT_4_1b->Add(h_VJ_pT_4_1b);
  err_hs_MC_pT_4_2b->Add(h_VJ_pT_4_2b);
  err_hs_MC_pT_4_3b->Add(h_VJ_pT_4_3b);
  err_hs_MC_pT_4_1b->Add(h_VV_pT_4_1b);
  err_hs_MC_pT_4_2b->Add(h_VV_pT_4_2b);
  err_hs_MC_pT_4_3b->Add(h_VV_pT_4_3b);
  err_hs_MC_pT_4_1b->Add(h_QCD_pT_4_1b);
  err_hs_MC_pT_4_2b->Add(h_QCD_pT_4_2b);
  err_hs_MC_pT_4_3b->Add(h_QCD_pT_4_3b);
  err_hs_MC_pT_4_1b->Add(h_TTX_pT_4_1b);
  err_hs_MC_pT_4_2b->Add(h_TTX_pT_4_2b);
  err_hs_MC_pT_4_3b->Add(h_TTX_pT_4_3b);




////////////////////////////////////////////// pT_4 1b ///////////////////////////////////////////////////////////////////


	TCanvas *c1 = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1 = new TPad("","",0,0.4,1,1);
        c1 -> cd();
  pad1->SetBottomMargin(0);
  pad1->Draw();
  pad1->cd();
//  pad1->SetLogy();



	hs_MC_pT_4_1b->Draw("hist");


	err_hs_MC_pT_4_1b->SetFillColor(kGray+2);
	err_hs_MC_pT_4_1b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_4_1b->SetMarkerStyle(1);
	err_hs_MC_pT_4_1b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_4_1b->SetFillStyle(3001);

        err_hs_MC_pT_4_1b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_4_1b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_4_1b->AddEntry(h_DATA_pT_4_1b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_4_1b->AddEntry(h_ST_pT_4_1b, "Single top", "f");
  legend_pt_4_1b->AddEntry(h_QCD_pT_4_1b, "QCD", "f");
  legend_pt_4_1b->AddEntry(h_VV_pT_4_1b, "VV", "f");

  legend_pt_4_1b->SetFillColor(0);
  legend_pt_4_1b->SetLineColor(0);
  legend_pt_4_1b->SetBorderSize(0);
  legend_pt_4_1b->SetTextFont(42); 
  legend_pt_4_1b->SetTextSize(0.045);              
  legend_pt_4_1b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_4_1b->SetEntrySeparation(0.3);
  legend_pt_4_1b->Draw();

  

  TLegend* legend_pt_4_1b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_4_1b_3->AddEntry(h_TT_pT_4_1b, "t#bar{t}", "f");
  legend_pt_4_1b_3->AddEntry(h_VJ_pT_4_1b, "VJ", "f");
  legend_pt_4_1b_3->AddEntry(h_TTX_pT_4_1b, "t#bar{t}X", "f"); 
  legend_pt_4_1b_3->AddEntry(err_hs_MC_pT_4_1b, "Stat. Error", "f"); 

  legend_pt_4_1b_3->SetFillColor(0);
  legend_pt_4_1b_3->SetLineColor(0);
  legend_pt_4_1b_3->SetBorderSize(0);
  legend_pt_4_1b_3->SetTextFont(42); 
  legend_pt_4_1b_3->SetTextSize(0.045);                                              
  legend_pt_4_1b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_4_1b_3->SetEntrySeparation(0.3);
  legend_pt_4_1b_3->Draw();



	h_DATA_pT_4_1b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_4_1b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_4_1b->Draw("epsame");

				TH1F* pT_4_1b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_4_1b_ratio_MC->Sumw2();

			  TH1F* pT_4_1b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_4_1b_one->Fill(i);
			  }
	 		  pT_4_1b_ratio_MC->Add(h_VV_pT_4_1b);
			  pT_4_1b_ratio_MC->Add(h_QCD_pT_4_1b);
			  pT_4_1b_ratio_MC->Add(h_VJ_pT_4_1b);
			  pT_4_1b_ratio_MC->Add(h_ST_pT_4_1b);
			  pT_4_1b_ratio_MC->Add(h_TT_pT_4_1b);
			  pT_4_1b_ratio_MC->Add(h_TTX_pT_4_1b);




			  c1->cd();
			  TPad *pad11 = new TPad("","",0,0.,1,0.4);
			  pad11->SetTopMargin(1);
			  pad11->Draw();
			  pad11->cd();

			  TH1F *pT_4_ratio_1b_DATA = (TH1F*)h_DATA_pT_4_1b->Clone();
			  pT_4_ratio_1b_DATA->Sumw2();
			  pT_4_ratio_1b_DATA->SetFillColor(15);
			  pT_4_ratio_1b_DATA->SetFillStyle(3002);

			  pT_4_ratio_1b_DATA->SetTitle("");
			  pT_4_ratio_1b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_4_ratio_1b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_4_ratio_1b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_4_ratio_1b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_4_ratio_1b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_4_ratio_1b_DATA->SetMinimum(0.6);
			  pT_4_ratio_1b_DATA->SetMaximum(1.6);
			  pT_4_ratio_1b_DATA->SetStats(0);
			  pT_4_ratio_1b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_4_ratio_1b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_4_ratio_1b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_4_ratio_1b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_4_ratio_1b_DATA->Divide(pT_4_1b_ratio_MC);


			  pT_4_ratio_1b_DATA->Draw("e");

			  pT_4_ratio_1b_DATA->SetMarkerStyle(20);
			  pT_4_ratio_1b_DATA->SetMarkerSize(0.5);
			  pT_4_ratio_1b_DATA->SetMarkerColor(1);
			  pT_4_ratio_1b_DATA->SetLineStyle(1);
			  pT_4_ratio_1b_DATA->Draw("same");
                          pT_4_1b_one->SetLineStyle(1);
	                  pT_4_1b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_4_1b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_4_1b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_4_1b_ratio_error->SetBinContent(i, 1);
			        pT_4_1b_ratio_error->SetBinError(i, pT_4_ratio_1b_DATA->GetBinError(i));
			  }

			  pT_4_1b_ratio_error->SetMarkerStyle(1);
			  pT_4_1b_ratio_error->SetFillColor(15);
			  pT_4_1b_ratio_error->SetFillStyle(3002);
			  pT_4_1b_ratio_error->Draw("E2same");

			//
	                  pT_4_1b_one->Draw("same");



     c1->SaveAs("hs_pT_4_1b.png");


////////////////////////////////////////////// pT_4 2b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_2b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_2b = new TPad("","",0,0.4,1,1);
        c1_2b -> cd();
  pad1_2b->SetBottomMargin(0);
  pad1_2b->Draw();
  pad1_2b->cd();
//  pad1->SetLogy();



	hs_MC_pT_4_2b->Draw("hist");


	err_hs_MC_pT_4_2b->SetFillColor(kGray+2);
	err_hs_MC_pT_4_2b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_4_2b->SetMarkerStyle(1);
	err_hs_MC_pT_4_2b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_4_2b->SetFillStyle(3001);

        err_hs_MC_pT_4_2b->Draw("E2Same");



	//The Labels
  TLegend* legend_pt_4_2b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_4_2b->AddEntry(h_DATA_pT_4_2b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_4_2b->AddEntry(h_ST_pT_4_2b, "Single top", "f");
  legend_pt_4_2b->AddEntry(h_QCD_pT_4_2b, "QCD", "f");
  legend_pt_4_2b->AddEntry(h_VV_pT_4_2b, "VV", "f");

  legend_pt_4_2b->SetFillColor(0);
  legend_pt_4_2b->SetLineColor(0);
  legend_pt_4_2b->SetBorderSize(0);
  legend_pt_4_2b->SetTextFont(42); 
  legend_pt_4_2b->SetTextSize(0.045);              
  legend_pt_4_2b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_4_2b->SetEntrySeparation(0.3);
  legend_pt_4_2b->Draw();

  

  TLegend* legend_pt_4_2b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_4_2b_3->AddEntry(h_TT_pT_4_2b, "t#bar{t}", "f");
  legend_pt_4_2b_3->AddEntry(h_VJ_pT_4_2b, "VJ", "f");
  legend_pt_4_2b_3->AddEntry(h_TTX_pT_4_2b, "t#bar{t}X", "f"); 
  legend_pt_4_2b_3->AddEntry(err_hs_MC_pT_4_2b, "Stat. Error", "f"); 

  legend_pt_4_2b_3->SetFillColor(0);
  legend_pt_4_2b_3->SetLineColor(0);
  legend_pt_4_2b_3->SetBorderSize(0);
  legend_pt_4_2b_3->SetTextFont(42); 
  legend_pt_4_2b_3->SetTextSize(0.045);                                              
  legend_pt_4_2b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_4_2b_3->SetEntrySeparation(0.3);
  legend_pt_4_2b_3->Draw();



	h_DATA_pT_4_2b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_4_2b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_4_2b->Draw("epsame");

				TH1F* pT_4_2b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_4_2b_ratio_MC->Sumw2();

			  TH1F* pT_4_2b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_4_2b_one->Fill(i);
			  }
	 		  pT_4_2b_ratio_MC->Add(h_VV_pT_4_2b);
			  pT_4_2b_ratio_MC->Add(h_QCD_pT_4_2b);
			  pT_4_2b_ratio_MC->Add(h_VJ_pT_4_2b);
			  pT_4_2b_ratio_MC->Add(h_ST_pT_4_2b);
			  pT_4_2b_ratio_MC->Add(h_TT_pT_4_2b);
			  pT_4_2b_ratio_MC->Add(h_TTX_pT_4_2b);



			  c1_2b->cd();
			  TPad *pad11_2b = new TPad("","",0,0.,1,0.4);
			  pad11_2b->SetTopMargin(1);
			  pad11_2b->Draw();
			  pad11_2b->cd();

			  TH1F *pT_4_ratio_2b_DATA = (TH1F*)h_DATA_pT_4_2b->Clone();
			  pT_4_ratio_2b_DATA->Sumw2();
			  pT_4_ratio_2b_DATA->SetFillColor(15);
			  pT_4_ratio_2b_DATA->SetFillStyle(3002);

			  pT_4_ratio_2b_DATA->SetTitle("");
			  pT_4_ratio_2b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_4_ratio_2b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_4_ratio_2b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_4_ratio_2b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_4_ratio_2b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_4_ratio_2b_DATA->SetMinimum(0.6);
			  pT_4_ratio_2b_DATA->SetMaximum(1.6);
			  pT_4_ratio_2b_DATA->SetStats(0);
			  pT_4_ratio_2b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_4_ratio_2b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_4_ratio_2b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_4_ratio_2b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_4_ratio_2b_DATA->Divide(pT_4_2b_ratio_MC);


			  pT_4_ratio_2b_DATA->Draw("e");

			  pT_4_ratio_2b_DATA->SetMarkerStyle(20);
			  pT_4_ratio_2b_DATA->SetMarkerSize(0.5);
			  pT_4_ratio_2b_DATA->SetMarkerColor(1);
			  pT_4_ratio_2b_DATA->SetLineStyle(1);
			  pT_4_ratio_2b_DATA->Draw("same");
                          pT_4_2b_one->SetLineStyle(1);
	                  pT_4_2b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_4_2b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_4_2b_ratio_error -> Sumw2();

			  for(int i=1; i< 300; i++){

				pT_4_2b_ratio_error->SetBinContent(i, 1);
			        pT_4_2b_ratio_error->SetBinError(i, pT_4_ratio_2b_DATA->GetBinError(i));
			  }

			  pT_4_2b_ratio_error->SetMarkerStyle(1);
			  pT_4_2b_ratio_error->SetFillColor(15);
			  pT_4_2b_ratio_error->SetFillStyle(3002);
			  pT_4_2b_ratio_error->Draw("E2same");

			//
	                  pT_4_2b_one->Draw("same");



     c1_2b->SaveAs("hs_pT_4_2b.png");


////////////////////////////////////////////// pT_4 3b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_3b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_3b = new TPad("","",0,0.4,1,1);
        c1_3b -> cd();
  pad1_3b->SetBottomMargin(0);
  pad1_3b->Draw();
  pad1_3b->cd();
//  pad1->SetLogy();



	hs_MC_pT_4_3b->Draw("hist");


	err_hs_MC_pT_4_3b->SetFillColor(kGray+2);
	err_hs_MC_pT_4_3b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_4_3b->SetMarkerStyle(1);
	err_hs_MC_pT_4_3b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_4_3b->SetFillStyle(3001);

        err_hs_MC_pT_4_3b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_4_3b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_4_3b->AddEntry(h_DATA_pT_4_3b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_4_3b->AddEntry(h_ST_pT_4_3b, "Single top", "f");
  legend_pt_4_3b->AddEntry(h_QCD_pT_4_3b, "QCD", "f");
  legend_pt_4_3b->AddEntry(h_VV_pT_4_3b, "VV", "f");

  legend_pt_4_3b->SetFillColor(0);
  legend_pt_4_3b->SetLineColor(0);
  legend_pt_4_3b->SetBorderSize(0);
  legend_pt_4_3b->SetTextFont(42); 
  legend_pt_4_3b->SetTextSize(0.045);              
  legend_pt_4_3b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_4_3b->SetEntrySeparation(0.3);
  legend_pt_4_3b->Draw();

  

  TLegend* legend_pt_4_3b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_4_3b_3->AddEntry(h_TT_pT_4_3b, "t#bar{t}", "f");
  legend_pt_4_3b_3->AddEntry(h_VJ_pT_4_3b, "VJ", "f");
  legend_pt_4_3b_3->AddEntry(h_TTX_pT_4_3b, "t#bar{t}X", "f"); 
  legend_pt_4_3b_3->AddEntry(err_hs_MC_pT_4_3b, "Stat. Error", "f"); 

  legend_pt_4_3b_3->SetFillColor(0);
  legend_pt_4_3b_3->SetLineColor(0);
  legend_pt_4_3b_3->SetBorderSize(0);
  legend_pt_4_3b_3->SetTextFont(42); 
  legend_pt_4_3b_3->SetTextSize(0.045);                                              
  legend_pt_4_3b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_4_3b_3->SetEntrySeparation(0.3);
  legend_pt_4_3b_3->Draw();


	h_DATA_pT_4_3b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_4_3b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_4_3b->Draw("epsame");

				TH1F* pT_4_3b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_4_3b_ratio_MC->Sumw2();

			  TH1F* pT_4_3b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_4_3b_one->Fill(i);
			  }
	 		  pT_4_3b_ratio_MC->Add(h_VV_pT_4_3b);
			  pT_4_3b_ratio_MC->Add(h_QCD_pT_4_3b);
			  pT_4_3b_ratio_MC->Add(h_VJ_pT_4_3b);
			  pT_4_3b_ratio_MC->Add(h_ST_pT_4_3b);
			  pT_4_3b_ratio_MC->Add(h_TT_pT_4_3b);
			  pT_4_3b_ratio_MC->Add(h_TTX_pT_4_3b);


//			  pT_4_3b_ratio_MC->Add(h_MC_TTX_0);

			  c1_3b->cd();
			  TPad *pad11_3b = new TPad("","",0,0.,1,0.4);
			  pad11_3b->SetTopMargin(1);
			  pad11_3b->Draw();
			  pad11_3b->cd();

			  TH1F *pT_4_ratio_3b_DATA = (TH1F*)h_DATA_pT_4_3b->Clone();
			  pT_4_ratio_3b_DATA->Sumw2();
			  pT_4_ratio_3b_DATA->SetFillColor(15);
			  pT_4_ratio_3b_DATA->SetFillStyle(3002);

			  pT_4_ratio_3b_DATA->SetTitle("");
			  pT_4_ratio_3b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_4_ratio_3b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_4_ratio_3b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_4_ratio_3b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_4_ratio_3b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_4_ratio_3b_DATA->SetMinimum(0.6);
			  pT_4_ratio_3b_DATA->SetMaximum(1.6);
			  pT_4_ratio_3b_DATA->SetStats(0);
			  pT_4_ratio_3b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_4_ratio_3b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_4_ratio_3b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_4_ratio_3b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_4_ratio_3b_DATA->Divide(pT_4_3b_ratio_MC);


			  pT_4_ratio_3b_DATA->Draw("e");

			  pT_4_ratio_3b_DATA->SetMarkerStyle(20);
			  pT_4_ratio_3b_DATA->SetMarkerSize(0.5);
			  pT_4_ratio_3b_DATA->SetMarkerColor(1);
			  pT_4_ratio_3b_DATA->SetLineStyle(1);
			  pT_4_ratio_3b_DATA->Draw("same");
                          pT_4_3b_one->SetLineStyle(1);
	                  pT_4_3b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_4_3b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_4_3b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_4_3b_ratio_error->SetBinContent(i, 1);
			        pT_4_3b_ratio_error->SetBinError(i, pT_4_ratio_3b_DATA->GetBinError(i));
			  }

			  pT_4_3b_ratio_error->SetMarkerStyle(1);
			  pT_4_3b_ratio_error->SetFillColor(15);
			  pT_4_3b_ratio_error->SetFillStyle(3002);
			  pT_4_3b_ratio_error->Draw("E2same");

			//
	                  pT_4_3b_one->Draw("same");



     c1_3b->SaveAs("hs_pT_4_3b.png");


//////////////// Stack pT_mu ////////////////////
  THStack *hs_MC_pT_mu_1b= new THStack("hs_pT_mu_1b","hs_pT_mu_1b");
  THStack *hs_MC_pT_mu_2b= new THStack("hs_pT_mu_2b","hs_pT_mu_2b");
  THStack *hs_MC_pT_mu_3b= new THStack("hs_pT_mu_3b","hs_pT_mu_3b");
h_TT_pT_mu_1b->SetLineColor(kRed);      h_TT_pT_mu_1b->SetFillColor(kRed);
h_TT_pT_mu_2b->SetLineColor(kRed);      h_TT_pT_mu_2b->SetFillColor(kRed);
h_TT_pT_mu_3b->SetLineColor(kRed);      h_TT_pT_mu_3b->SetFillColor(kRed);

h_ST_pT_mu_1b->SetLineColor(kMagenta);      h_ST_pT_mu_1b->SetFillColor(kMagenta);
h_ST_pT_mu_2b->SetLineColor(kMagenta);      h_ST_pT_mu_2b->SetFillColor(kMagenta);
h_ST_pT_mu_3b->SetLineColor(kMagenta);      h_ST_pT_mu_3b->SetFillColor(kMagenta);

h_VJ_pT_mu_1b->SetLineColor(kOrange);      h_VJ_pT_mu_1b->SetFillColor(kOrange);
h_VJ_pT_mu_2b->SetLineColor(kOrange);      h_VJ_pT_mu_2b->SetFillColor(kOrange);
h_VJ_pT_mu_3b->SetLineColor(kOrange);      h_VJ_pT_mu_3b->SetFillColor(kOrange);

h_VV_pT_mu_1b->SetLineColor(kGreen+1);      h_VV_pT_mu_1b->SetFillColor(kGreen+1);
h_VV_pT_mu_2b->SetLineColor(kGreen+1);      h_VV_pT_mu_2b->SetFillColor(kGreen+1);
h_VV_pT_mu_3b->SetLineColor(kGreen+1);      h_VV_pT_mu_3b->SetFillColor(kGreen+1);

h_QCD_pT_mu_1b->SetLineColor(kCyan);      h_QCD_pT_mu_1b->SetFillColor(kCyan);
h_QCD_pT_mu_2b->SetLineColor(kCyan);      h_QCD_pT_mu_2b->SetFillColor(kCyan);
h_QCD_pT_mu_3b->SetLineColor(kCyan);      h_QCD_pT_mu_3b->SetFillColor(kCyan);

h_TTX_pT_mu_1b->SetLineColor(kYellow);      h_TTX_pT_mu_1b->SetFillColor(kYellow);
h_TTX_pT_mu_2b->SetLineColor(kYellow);      h_TTX_pT_mu_2b->SetFillColor(kYellow);
h_TTX_pT_mu_3b->SetLineColor(kYellow);      h_TTX_pT_mu_3b->SetFillColor(kYellow);


  hs_MC_pT_mu_1b->Add(h_TT_pT_mu_1b);
  hs_MC_pT_mu_2b->Add(h_TT_pT_mu_2b);
  hs_MC_pT_mu_3b->Add(h_TT_pT_mu_3b);
  hs_MC_pT_mu_1b->Add(h_ST_pT_mu_1b);
  hs_MC_pT_mu_2b->Add(h_ST_pT_mu_2b);
  hs_MC_pT_mu_3b->Add(h_ST_pT_mu_3b);
  hs_MC_pT_mu_1b->Add(h_VJ_pT_mu_1b);
  hs_MC_pT_mu_2b->Add(h_VJ_pT_mu_2b);
  hs_MC_pT_mu_3b->Add(h_VJ_pT_mu_3b);
  hs_MC_pT_mu_1b->Add(h_VV_pT_mu_1b);
  hs_MC_pT_mu_2b->Add(h_VV_pT_mu_2b);
  hs_MC_pT_mu_3b->Add(h_VV_pT_mu_3b);
  hs_MC_pT_mu_1b->Add(h_QCD_pT_mu_1b);
  hs_MC_pT_mu_2b->Add(h_QCD_pT_mu_2b);
  hs_MC_pT_mu_3b->Add(h_QCD_pT_mu_3b);
  hs_MC_pT_mu_1b->Add(h_TTX_pT_mu_1b);
  hs_MC_pT_mu_2b->Add(h_TTX_pT_mu_2b);
  hs_MC_pT_mu_3b->Add(h_TTX_pT_mu_3b);



//MC error

        TH1F *err_hs_MC_pT_mu_1b = new TH1F("err_hs_MC_pT_mu_1b", "err_hs_MC_pT_mu_1b", 60, 0, 300);
        TH1F *err_hs_MC_pT_mu_2b = new TH1F("err_hs_MC_pT_mu_2b", "err_hs_MC_pT_mu_2b", 60, 0, 300);
        TH1F *err_hs_MC_pT_mu_3b = new TH1F("err_hs_MC_pT_mu_3b", "err_hs_MC_pT_mu_3b", 60, 0, 300);



  err_hs_MC_pT_mu_1b->Sumw2();
  err_hs_MC_pT_mu_2b->Sumw2();
  err_hs_MC_pT_mu_3b->Sumw2();


   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
   cout << "debug!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;


  err_hs_MC_pT_mu_1b->Add(h_TT_pT_mu_1b);
  err_hs_MC_pT_mu_2b->Add(h_TT_pT_mu_2b);
  err_hs_MC_pT_mu_3b->Add(h_TT_pT_mu_3b);
  err_hs_MC_pT_mu_1b->Add(h_ST_pT_mu_1b);
  err_hs_MC_pT_mu_2b->Add(h_ST_pT_mu_2b);
  err_hs_MC_pT_mu_3b->Add(h_ST_pT_mu_3b);
  err_hs_MC_pT_mu_1b->Add(h_VJ_pT_mu_1b);
  err_hs_MC_pT_mu_2b->Add(h_VJ_pT_mu_2b);
  err_hs_MC_pT_mu_3b->Add(h_VJ_pT_mu_3b);
  err_hs_MC_pT_mu_1b->Add(h_VV_pT_mu_1b);
  err_hs_MC_pT_mu_2b->Add(h_VV_pT_mu_2b);
  err_hs_MC_pT_mu_3b->Add(h_VV_pT_mu_3b);
  err_hs_MC_pT_mu_1b->Add(h_QCD_pT_mu_1b);
  err_hs_MC_pT_mu_2b->Add(h_QCD_pT_mu_2b);
  err_hs_MC_pT_mu_3b->Add(h_QCD_pT_mu_3b);
  err_hs_MC_pT_mu_1b->Add(h_TTX_pT_mu_1b);
  err_hs_MC_pT_mu_2b->Add(h_TTX_pT_mu_2b);
  err_hs_MC_pT_mu_3b->Add(h_TTX_pT_mu_3b);




////////////////////////////////////////////// pT_mu 1b ///////////////////////////////////////////////////////////////////


	TCanvas *c1 = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1 = new TPad("","",0,0.4,1,1);
        c1 -> cd();
  pad1->SetBottomMargin(0);
  pad1->Draw();
  pad1->cd();
//  pad1->SetLogy();



	hs_MC_pT_mu_1b->Draw("hist");


	err_hs_MC_pT_mu_1b->SetFillColor(kGray+2);
	err_hs_MC_pT_mu_1b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_mu_1b->SetMarkerStyle(1);
	err_hs_MC_pT_mu_1b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_mu_1b->SetFillStyle(3001);

        err_hs_MC_pT_mu_1b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_mu_1b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_mu_1b->AddEntry(h_DATA_pT_mu_1b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_mu_1b->AddEntry(h_ST_pT_mu_1b, "Single top", "f");
  legend_pt_mu_1b->AddEntry(h_QCD_pT_mu_1b, "QCD", "f");
  legend_pt_mu_1b->AddEntry(h_VV_pT_mu_1b, "VV", "f");

  legend_pt_mu_1b->SetFillColor(0);
  legend_pt_mu_1b->SetLineColor(0);
  legend_pt_mu_1b->SetBorderSize(0);
  legend_pt_mu_1b->SetTextFont(42); 
  legend_pt_mu_1b->SetTextSize(0.045);              
  legend_pt_mu_1b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_mu_1b->SetEntrySeparation(0.3);
  legend_pt_mu_1b->Draw();

  

  TLegend* legend_pt_mu_1b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_mu_1b_3->AddEntry(h_TT_pT_mu_1b, "t#bar{t}", "f");
  legend_pt_mu_1b_3->AddEntry(h_VJ_pT_mu_1b, "VJ", "f");
  legend_pt_mu_1b_3->AddEntry(h_TTX_pT_mu_1b, "t#bar{t}X", "f"); 
  legend_pt_mu_1b_3->AddEntry(err_hs_MC_pT_mu_1b, "Stat. Error", "f"); 

  legend_pt_mu_1b_3->SetFillColor(0);
  legend_pt_mu_1b_3->SetLineColor(0);
  legend_pt_mu_1b_3->SetBorderSize(0);
  legend_pt_mu_1b_3->SetTextFont(42); 
  legend_pt_mu_1b_3->SetTextSize(0.045);                                              
  legend_pt_mu_1b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_mu_1b_3->SetEntrySeparation(0.3);
  legend_pt_mu_1b_3->Draw();


	h_DATA_pT_mu_1b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_mu_1b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_mu_1b->Draw("epsame");

				TH1F* pT_mu_1b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_mu_1b_ratio_MC->Sumw2();

			  TH1F* pT_mu_1b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_mu_1b_one->Fill(i);
			  }
	 		  pT_mu_1b_ratio_MC->Add(h_VV_pT_mu_1b);
			  pT_mu_1b_ratio_MC->Add(h_QCD_pT_mu_1b);
			  pT_mu_1b_ratio_MC->Add(h_VJ_pT_mu_1b);
			  pT_mu_1b_ratio_MC->Add(h_ST_pT_mu_1b);
			  pT_mu_1b_ratio_MC->Add(h_TT_pT_mu_1b);
			  pT_mu_1b_ratio_MC->Add(h_TTX_pT_mu_1b);




			  c1->cd();
			  TPad *pad11 = new TPad("","",0,0.,1,0.4);
			  pad11->SetTopMargin(1);
			  pad11->Draw();
			  pad11->cd();

			  TH1F *pT_mu_ratio_1b_DATA = (TH1F*)h_DATA_pT_mu_1b->Clone();
			  pT_mu_ratio_1b_DATA->Sumw2();
			  pT_mu_ratio_1b_DATA->SetFillColor(15);
			  pT_mu_ratio_1b_DATA->SetFillStyle(3002);

			  pT_mu_ratio_1b_DATA->SetTitle("");
			  pT_mu_ratio_1b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_mu_ratio_1b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_mu_ratio_1b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_mu_ratio_1b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_mu_ratio_1b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_mu_ratio_1b_DATA->SetMinimum(0.6);
			  pT_mu_ratio_1b_DATA->SetMaximum(1.6);
			  pT_mu_ratio_1b_DATA->SetStats(0);
			  pT_mu_ratio_1b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_mu_ratio_1b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_mu_ratio_1b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_mu_ratio_1b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_mu_ratio_1b_DATA->Divide(pT_mu_1b_ratio_MC);


			  pT_mu_ratio_1b_DATA->Draw("e");

			  pT_mu_ratio_1b_DATA->SetMarkerStyle(20);
			  pT_mu_ratio_1b_DATA->SetMarkerSize(0.5);
			  pT_mu_ratio_1b_DATA->SetMarkerColor(1);
			  pT_mu_ratio_1b_DATA->SetLineStyle(1);
			  pT_mu_ratio_1b_DATA->Draw("same");
                          pT_mu_1b_one->SetLineStyle(1);
	                  pT_mu_1b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_mu_1b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_mu_1b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_mu_1b_ratio_error->SetBinContent(i, 1);
			        pT_mu_1b_ratio_error->SetBinError(i, pT_mu_ratio_1b_DATA->GetBinError(i));
			  }

			  pT_mu_1b_ratio_error->SetMarkerStyle(1);
			  pT_mu_1b_ratio_error->SetFillColor(15);
			  pT_mu_1b_ratio_error->SetFillStyle(3002);
			  pT_mu_1b_ratio_error->Draw("E2same");

			//
	                  pT_mu_1b_one->Draw("same");



     c1->SaveAs("hs_pT_mu_1b.png");


////////////////////////////////////////////// pT_mu 2b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_2b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_2b = new TPad("","",0,0.4,1,1);
        c1_2b -> cd();
  pad1_2b->SetBottomMargin(0);
  pad1_2b->Draw();
  pad1_2b->cd();
//  pad1->SetLogy();



	hs_MC_pT_mu_2b->Draw("hist");


	err_hs_MC_pT_mu_2b->SetFillColor(kGray+2);
	err_hs_MC_pT_mu_2b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_mu_2b->SetMarkerStyle(1);
	err_hs_MC_pT_mu_2b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_mu_2b->SetFillStyle(3001);

        err_hs_MC_pT_mu_2b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_mu_2b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_mu_2b->AddEntry(h_DATA_pT_mu_2b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_mu_2b->AddEntry(h_ST_pT_mu_2b, "Single top", "f");
  legend_pt_mu_2b->AddEntry(h_QCD_pT_mu_2b, "QCD", "f");
  legend_pt_mu_2b->AddEntry(h_VV_pT_mu_2b, "VV", "f");

  legend_pt_mu_2b->SetFillColor(0);
  legend_pt_mu_2b->SetLineColor(0);
  legend_pt_mu_2b->SetBorderSize(0);
  legend_pt_mu_2b->SetTextFont(42); 
  legend_pt_mu_2b->SetTextSize(0.045);              
  legend_pt_mu_2b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_mu_2b->SetEntrySeparation(0.3);
  legend_pt_mu_2b->Draw();

  

  TLegend* legend_pt_mu_2b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_mu_2b_3->AddEntry(h_TT_pT_mu_2b, "t#bar{t}", "f");
  legend_pt_mu_2b_3->AddEntry(h_VJ_pT_mu_2b, "VJ", "f");
  legend_pt_mu_2b_3->AddEntry(h_TTX_pT_mu_2b, "t#bar{t}X", "f"); 
  legend_pt_mu_2b_3->AddEntry(err_hs_MC_pT_mu_2b, "Stat. Error", "f"); 

  legend_pt_mu_2b_3->SetFillColor(0);
  legend_pt_mu_2b_3->SetLineColor(0);
  legend_pt_mu_2b_3->SetBorderSize(0);
  legend_pt_mu_2b_3->SetTextFont(42); 
  legend_pt_mu_2b_3->SetTextSize(0.045);                                              
  legend_pt_mu_2b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_mu_2b_3->SetEntrySeparation(0.3);
  legend_pt_mu_2b_3->Draw();


	h_DATA_pT_mu_2b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_mu_2b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_mu_2b->Draw("epsame");

				TH1F* pT_mu_2b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_mu_2b_ratio_MC->Sumw2();

			  TH1F* pT_mu_2b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_mu_2b_one->Fill(i);
			  }
	 		  pT_mu_2b_ratio_MC->Add(h_VV_pT_mu_2b);
			  pT_mu_2b_ratio_MC->Add(h_QCD_pT_mu_2b);
			  pT_mu_2b_ratio_MC->Add(h_VJ_pT_mu_2b);
			  pT_mu_2b_ratio_MC->Add(h_ST_pT_mu_2b);
			  pT_mu_2b_ratio_MC->Add(h_TT_pT_mu_2b);
			  pT_mu_2b_ratio_MC->Add(h_TTX_pT_mu_2b);



			  c1_2b->cd();
			  TPad *pad11_2b = new TPad("","",0,0.,1,0.4);
			  pad11_2b->SetTopMargin(1);
			  pad11_2b->Draw();
			  pad11_2b->cd();

			  TH1F *pT_mu_ratio_2b_DATA = (TH1F*)h_DATA_pT_mu_2b->Clone();
			  pT_mu_ratio_2b_DATA->Sumw2();
			  pT_mu_ratio_2b_DATA->SetFillColor(15);
			  pT_mu_ratio_2b_DATA->SetFillStyle(3002);

			  pT_mu_ratio_2b_DATA->SetTitle("");
			  pT_mu_ratio_2b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_mu_ratio_2b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_mu_ratio_2b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_mu_ratio_2b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_mu_ratio_2b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_mu_ratio_2b_DATA->SetMinimum(0.6);
			  pT_mu_ratio_2b_DATA->SetMaximum(1.6);
			  pT_mu_ratio_2b_DATA->SetStats(0);
			  pT_mu_ratio_2b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_mu_ratio_2b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_mu_ratio_2b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_mu_ratio_2b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_mu_ratio_2b_DATA->Divide(pT_mu_2b_ratio_MC);


			  pT_mu_ratio_2b_DATA->Draw("e");

			  pT_mu_ratio_2b_DATA->SetMarkerStyle(20);
			  pT_mu_ratio_2b_DATA->SetMarkerSize(0.5);
			  pT_mu_ratio_2b_DATA->SetMarkerColor(1);
			  pT_mu_ratio_2b_DATA->SetLineStyle(1);
			  pT_mu_ratio_2b_DATA->Draw("same");
                          pT_mu_2b_one->SetLineStyle(1);
	                  pT_mu_2b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_mu_2b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_mu_2b_ratio_error -> Sumw2();

			  for(int i=1; i< 300; i++){

				pT_mu_2b_ratio_error->SetBinContent(i, 1);
			        pT_mu_2b_ratio_error->SetBinError(i, pT_mu_ratio_2b_DATA->GetBinError(i));
			  }

			  pT_mu_2b_ratio_error->SetMarkerStyle(1);
			  pT_mu_2b_ratio_error->SetFillColor(15);
			  pT_mu_2b_ratio_error->SetFillStyle(3002);
			  pT_mu_2b_ratio_error->Draw("E2same");

			//
	                  pT_mu_2b_one->Draw("same");



     c1_2b->SaveAs("hs_pT_mu_2b.png");


////////////////////////////////////////////// pT_mu 3b ///////////////////////////////////////////////////////////////////


	TCanvas *c1_3b = new TCanvas("c1", "", 800, 600);    // Canvas
	TPad *pad1_3b = new TPad("","",0,0.4,1,1);
        c1_3b -> cd();
  pad1_3b->SetBottomMargin(0);
  pad1_3b->Draw();
  pad1_3b->cd();
//  pad1->SetLogy();



	hs_MC_pT_mu_3b->Draw("hist");


	err_hs_MC_pT_mu_3b->SetFillColor(kGray+2);
	err_hs_MC_pT_mu_3b->SetMarkerColorAlpha(kGray+2, 1);
	err_hs_MC_pT_mu_3b->SetMarkerStyle(1);
	err_hs_MC_pT_mu_3b->SetFillColorAlpha(kGray+2, 1);
 	err_hs_MC_pT_mu_3b->SetFillStyle(3001);

        err_hs_MC_pT_mu_3b->Draw("E2Same");


	//The Labels
  TLegend* legend_pt_mu_3b =  new TLegend(0.58,0.57,0.76,0.82);  //Position and size of the Label (x1,y1,x2,y2)
  legend_pt_mu_3b->AddEntry(h_DATA_pT_mu_3b, "Data", "p");  // "p" means point, "f" means box, "l" means line

  legend_pt_mu_3b->AddEntry(h_ST_pT_mu_3b, "Single top", "f");
  legend_pt_mu_3b->AddEntry(h_QCD_pT_mu_3b, "QCD", "f");
  legend_pt_mu_3b->AddEntry(h_VV_pT_mu_3b, "VV", "f");

  legend_pt_mu_3b->SetFillColor(0);
  legend_pt_mu_3b->SetLineColor(0);
  legend_pt_mu_3b->SetBorderSize(0);
  legend_pt_mu_3b->SetTextFont(42); 
  legend_pt_mu_3b->SetTextSize(0.045);              
  legend_pt_mu_3b->SetShadowColor(0); // 0 = transparent                    
  legend_pt_mu_3b->SetEntrySeparation(0.3);
  legend_pt_mu_3b->Draw();

  

  TLegend* legend_pt_mu_3b_3 =  new TLegend(0.76,0.56,0.94,0.81);  //Position and size of the Label (x1,y1,x2,y2)

  legend_pt_mu_3b_3->AddEntry(h_TT_pT_mu_3b, "t#bar{t}", "f");
  legend_pt_mu_3b_3->AddEntry(h_VJ_pT_mu_3b, "VJ", "f");
  legend_pt_mu_3b_3->AddEntry(h_TTX_pT_mu_3b, "t#bar{t}X", "f"); 
  legend_pt_mu_3b_3->AddEntry(err_hs_MC_pT_mu_3b, "Stat. Error", "f"); 

  legend_pt_mu_3b_3->SetFillColor(0);
  legend_pt_mu_3b_3->SetLineColor(0);
  legend_pt_mu_3b_3->SetBorderSize(0);
  legend_pt_mu_3b_3->SetTextFont(42); 
  legend_pt_mu_3b_3->SetTextSize(0.045);                                              
  legend_pt_mu_3b_3->SetShadowColor(0); // 0 = transparent                    
  legend_pt_mu_3b_3->SetEntrySeparation(0.3);
  legend_pt_mu_3b_3->Draw();


	h_DATA_pT_mu_3b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_pT_mu_3b->SetMarkerSize(1.);  //size of the signs
        h_DATA_pT_mu_3b->Draw("epsame");

				TH1F* pT_mu_3b_ratio_MC = new TH1F("","", 60, 0, 300);

			  pT_mu_3b_ratio_MC->Sumw2();

			  TH1F* pT_mu_3b_one = new TH1F("","", 300, 0, 300);
			  for(int i=0; i<300; i++){
			        pT_mu_3b_one->Fill(i);
			  }
	 		  pT_mu_3b_ratio_MC->Add(h_VV_pT_mu_3b);
			  pT_mu_3b_ratio_MC->Add(h_QCD_pT_mu_3b);
			  pT_mu_3b_ratio_MC->Add(h_VJ_pT_mu_3b);
			  pT_mu_3b_ratio_MC->Add(h_ST_pT_mu_3b);
			  pT_mu_3b_ratio_MC->Add(h_TT_pT_mu_3b);
			  pT_mu_3b_ratio_MC->Add(h_TTX_pT_mu_3b);


//			  pT_mu_3b_ratio_MC->Add(h_MC_TTX_0);

			  c1_3b->cd();
			  TPad *pad11_3b = new TPad("","",0,0.,1,0.4);
			  pad11_3b->SetTopMargin(1);
			  pad11_3b->Draw();
			  pad11_3b->cd();

			  TH1F *pT_mu_ratio_3b_DATA = (TH1F*)h_DATA_pT_mu_3b->Clone();
			  pT_mu_ratio_3b_DATA->Sumw2();
			  pT_mu_ratio_3b_DATA->SetFillColor(15);
			  pT_mu_ratio_3b_DATA->SetFillStyle(3002);

			  pT_mu_ratio_3b_DATA->SetTitle("");
			  pT_mu_ratio_3b_DATA->GetYaxis()->SetTitle("Data / MC");
			  pT_mu_ratio_3b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  pT_mu_ratio_3b_DATA->GetXaxis()->SetTitleSize(0.15);
			  pT_mu_ratio_3b_DATA->GetXaxis()->SetLabelSize(0.1);
			  pT_mu_ratio_3b_DATA->GetYaxis()->SetLabelSize(0.08);
			  pT_mu_ratio_3b_DATA->SetMinimum(0.6);
			  pT_mu_ratio_3b_DATA->SetMaximum(1.6);
			  pT_mu_ratio_3b_DATA->SetStats(0);
			  pT_mu_ratio_3b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  pT_mu_ratio_3b_DATA->GetYaxis()->SetTitleFont(43);
			  pT_mu_ratio_3b_DATA->GetYaxis()->SetTitleSize(23);
			  pT_mu_ratio_3b_DATA->GetYaxis()->SetNdivisions(5);
			  pT_mu_ratio_3b_DATA->Divide(pT_mu_3b_ratio_MC);


			  pT_mu_ratio_3b_DATA->Draw("e");

			  pT_mu_ratio_3b_DATA->SetMarkerStyle(20);
			  pT_mu_ratio_3b_DATA->SetMarkerSize(0.5);
			  pT_mu_ratio_3b_DATA->SetMarkerColor(1);
			  pT_mu_ratio_3b_DATA->SetLineStyle(1);
			  pT_mu_ratio_3b_DATA->Draw("same");
                          pT_mu_3b_one->SetLineStyle(1);
	                  pT_mu_3b_one->Draw("same");

			// ratio error centered at 1

			TH1F* pT_mu_3b_ratio_error = new TH1F("","", 60, 0, 300);

			pT_mu_3b_ratio_error -> Sumw2();

			  for(int i=1; i< 60; i++){

				pT_mu_3b_ratio_error->SetBinContent(i, 1);
			        pT_mu_3b_ratio_error->SetBinError(i, pT_mu_ratio_3b_DATA->GetBinError(i));
			  }

			  pT_mu_3b_ratio_error->SetMarkerStyle(1);
			  pT_mu_3b_ratio_error->SetFillColor(15);
			  pT_mu_3b_ratio_error->SetFillStyle(3002);
			  pT_mu_3b_ratio_error->Draw("E2same");

			//
	                  pT_mu_3b_one->Draw("same");



     c1_3b->SaveAs("hs_pT_mu_3b.png");


}




/*
////////////////////////////////////////////// nVer 2b ///////////////////////////////////////////////////////////////////


	TCanvas *c2 = new TCanvas("c2", "", 800, 600);    // Canvas
	TPad *pad2 = new TPad("","",0,0.4,1,1);
        c2->cd();
  pad2->SetBottomMargin(0);
  pad2->Draw();
  pad2->cd();
  pad2->SetLogy();



	hs_MC_nVer_2b->Draw("hist");



	h_DATA_nVer_2b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_nVer_2b->SetMarkerSize(1.);  //size of the signs
        h_DATA_nVer_2b->Draw("epsame");

				TH1F* nVer_2b_ratio_MC = new TH1F("","",50, 0, 50);

			  nVer_2b_ratio_MC->Sumw2();

			  TH1F* nVer_2b_one = new TH1F("","", 200, -100, 100);
			  for(int i=-100; i<100; i++){
			        nVer_2b_one->Fill(i);
			  }
//	 		  nVer_ratio_MC->Add(h_MC_VV_0);
//			  nVer_ratio_MC->Add(h_MC_ST_0);
//			  nVer_ratio_MC->Add(h_MC_VJ_0);
			  nVer_2b_ratio_MC->Add(h_TT_nVer_2b);


//			  nVer_ratio_MC->Add(h_MC_TTX_0);

			  c2->cd();
			  TPad *pad22 = new TPad("","",0,0.,1,0.4);
			  pad22->SetTopMargin(1);
			  pad22->Draw();
			  pad22->cd();

			  TH1F *nVer_ratio_2b_DATA = (TH1F*)h_DATA_nVer_2b->Clone();
			  nVer_ratio_2b_DATA->Sumw2();
			  nVer_ratio_2b_DATA->SetFillColor(15);
			  nVer_ratio_2b_DATA->SetFillStyle(3002);

			  nVer_ratio_2b_DATA->SetTitle("");
			  nVer_ratio_2b_DATA->GetYaxis()->SetTitle("Data / MC");
			  nVer_ratio_2b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  nVer_ratio_2b_DATA->GetXaxis()->SetTitleSize(0.15);
			  nVer_ratio_2b_DATA->GetXaxis()->SetLabelSize(0.1);
			  nVer_ratio_2b_DATA->GetYaxis()->SetLabelSize(0.08);
			  nVer_ratio_2b_DATA->GetXaxis()->SetRangeUser(20.,300.);
			  nVer_ratio_2b_DATA->SetMinimum(0.6);
			  nVer_ratio_2b_DATA->SetMaximum(1.6);
			  nVer_ratio_2b_DATA->SetStats(0);
			  nVer_ratio_2b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  nVer_ratio_2b_DATA->GetYaxis()->SetTitleFont(43);
			  nVer_ratio_2b_DATA->GetYaxis()->SetTitleSize(23);
			  nVer_ratio_2b_DATA->GetYaxis()->SetNdivisions(5);
			  nVer_ratio_2b_DATA->Divide(nVer_2b_ratio_MC);


			  nVer_ratio_2b_DATA->Draw("e");

			  nVer_ratio_2b_DATA->SetMarkerStyle(20);
			  nVer_ratio_2b_DATA->SetMarkerSize(0.5);
			  nVer_ratio_2b_DATA->SetMarkerColor(1);
			  nVer_ratio_2b_DATA->SetLineStyle(1);
			  nVer_ratio_2b_DATA->Draw("same");

			// ratio error centered at 1

			TH1F* nVer_2b_ratio_error = new TH1F("","",50, 0, 50);

			nVer_2b_ratio_error -> Sumw2();

			  for(int i=1; i< 51; i++){

				nVer_2b_ratio_error->SetBinContent(i, 1);
			        nVer_2b_ratio_error->SetBinError(i, nVer_2b_ratio_DATA->GetBinError(i));
			  }

			  nVer_2b_ratio_error->SetMarkerStyle(1);
			  nVer_2b_ratio_error->SetFillColor(15);
			  nVer_2b_ratio_error->SetFillStyle(3002);
			  nVer_2b_ratio_error->Draw("e3same");

			//

			  nVer_2b_one->Draw("same");
			  nVer_2b_ratio_DATA->Draw("pesame");



c->SaveAs("hs_nVer_2b.png");


//////////////////////////////////////////////// nVer 3b /////////////////////////////////////////////////////////////////


	TCanvas *c3 = new TCanvas("c3", "", 800, 600);    // Canvas
	TPad *pad3 = new TPad("","",0,0.4,1,1);
        c3->cd();
  pad3->SetBottomMargin(0);
  pad3->Draw();
  pad3->cd();
  pad3->SetLogy();



	hs_MC_nVer_3b->Draw("hist");



	h_DATA_nVer_3b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_nVer_3b->SetMarkerSize(1.);  //size of the signs
        h_DATA_nVer_3b->Draw("epsame");

				TH1F* nVer_3b_ratio_MC = new TH1F("","",50, 0, 50);

			  nVer_3b_ratio_MC->Sumw2();

			  TH1F* nVer_3b_one = new TH1F("","", 200, -100, 100);
			  for(int i=-100; i<100; i++){
			        nVer_3b_one->Fill(i);
			  }
//	 		  nVer_ratio_MC->Add(h_MC_VV_0);
//			  nVer_ratio_MC->Add(h_MC_ST_0);
//			  nVer_ratio_MC->Add(h_MC_VJ_0);
			  nVer_3b_ratio_MC->Add(h_TT_nVer_3b);


//			  nVer_ratio_MC->Add(h_MC_TTX_0);

			  c3->cd();
			  TPad *pad32 = new TPad("","",0,0.,1,0.4);
			  pad32->SetTopMargin(1);
			  pad32->Draw();
			  pad32->cd();

			  TH1F *nVer_ratio_3b_DATA = (TH1F*)h_DATA_nVer_3b->Clone();
			  nVer_ratio_3b_DATA->Sumw2();
			  nVer_ratio_3b_DATA->SetFillColor(15);
			  nVer_ratio_3b_DATA->SetFillStyle(3002);

			  nVer_ratio_3b_DATA->SetTitle("");
			  nVer_ratio_3b_DATA->GetYaxis()->SetTitle("Data / MC");
			  nVer_ratio_3b_DATA->GetXaxis()->SetTitle("Muon p_{T} [GeV]");
			  nVer_ratio_3b_DATA->GetXaxis()->SetTitleSize(0.15);
			  nVer_ratio_3b_DATA->GetXaxis()->SetLabelSize(0.1);
			  nVer_ratio_3b_DATA->GetYaxis()->SetLabelSize(0.08);
			  nVer_ratio_3b_DATA->GetXaxis()->SetRangeUser(20.,300.);
			  nVer_ratio_3b_DATA->SetMinimum(0.6);
			  nVer_ratio_3b_DATA->SetMaximum(1.6);
			  nVer_ratio_3b_DATA->SetStats(0);
			  nVer_ratio_3b_DATA->GetYaxis()->SetTitleOffset(1.8);
			  nVer_ratio_3b_DATA->GetYaxis()->SetTitleFont(43);
			  nVer_ratio_3b_DATA->GetYaxis()->SetTitleSize(23);
			  nVer_ratio_3b_DATA->GetYaxis()->SetNdivisions(5);
			  nVer_ratio_3b_DATA->Divide(nVer_3b_ratio_MC);


			  nVer_ratio_3b_DATA->Draw("e");

			  nVer_ratio_3b_DATA->SetMarkerStyle(20);
			  nVer_ratio_3b_DATA->SetMarkerSize(0.5);
			  nVer_ratio_3b_DATA->SetMarkerColor(1);
			  nVer_ratio_3b_DATA->SetLineStyle(1);
			  nVer_ratio_3b_DATA->Draw("same");

			// ratio error centered at 1

			TH1F* nVer_3b_ratio_error = new TH1F("","",50, 0, 50);

			nVer_3b_ratio_error -> Sumw2();

			  for(int i=1; i< 51; i++){

				nVer_3b_ratio_error->SetBinContent(i, 1);
			        nVer_3b_ratio_error->SetBinError(i, nVer_3b_ratio_DATA->GetBinError(i));
			  }

			  nVer_3b_ratio_error->SetMarkerStyle(1);
			  nVer_3b_ratio_error->SetFillColor(15);
			  nVer_3b_ratio_error->SetFillStyle(3002);
			  nVer_3b_ratio_error->Draw("e3same");

			//

			  nVer_3b_one->Draw("same");
			  nVer_3b_ratio_DATA->Draw("pesame");



c->SaveAs("hs_nVer_3b.png");


*/


void SetBranchAddress(TNtuple &*tuple, TFile &*tfile){

   tuple = (TNtuple*) tfile->Get("tuple_var");


   tuple->SetBranchAddress("Trigger_SF", &Trigger_SF);
   tuple->SetBranchAddress("Trigger_SF_UP", &Trigger_SF_UP);
   tuple->SetBranchAddress("Trigger_SF_DOWN", &Trigger_SF_DOWN);

   tuple->SetBranchAddress("MuonTrack_SF", &MuonTrack_SF);
   tuple->SetBranchAddress("Muon_SF", &Muon_SF);
   tuple->SetBranchAddress("Muon_SF_UP", &Muon_SF_UP);
   tuple->SetBranchAddress("Muon_SF_DOWN", &Muon_SF_DOWN);
   tuple->SetBranchAddress("MuonISO_SF", &MuonISO_SF);
   tuple->SetBranchAddress("MuonISO_SF_UP", &MuonISO_SF_UP);
   tuple->SetBranchAddress("MuonISO_SF_DOWN", &MuonISO_SF_DOWN);

   tuple->SetBranchAddress("weight_by_trigger", &weight_by_trigger);
   tuple->SetBranchAddress("weight", &weight);
   tuple->SetBranchAddress("MCweight", &MCweight);
   tuple->SetBranchAddress("PU", &PU);
   tuple->SetBranchAddress("PU_UP", &PU_UP);
   tuple->SetBranchAddress("PU_DOWN", &PU_DOWN);
   tuple->SetBranchAddress("BTag_SF", &BTag_SF);
   tuple->SetBranchAddress("nbtags", &nbtags);
   tuple->SetBranchAddress("nVer", &nVer);
   tuple->SetBranchAddress("njets", &njets);
   tuple->SetBranchAddress("Mu_Pt", &Mu_Pt);
   tuple->SetBranchAddress("Mu_Eta", &Mu_Eta);
   tuple->SetBranchAddress("METv", &METv);
   tuple->SetBranchAddress("jet_Pt1", &jet_Pt1);
   tuple->SetBranchAddress("jet_Pt2", &jet_Pt2);
   tuple->SetBranchAddress("jet_Pt3", &jet_Pt3);
   tuple->SetBranchAddress("jet_Pt4", &jet_Pt4);
   tuple->SetBranchAddress("jet_Eta1", &jet_Eta1);
   tuple->SetBranchAddress("jet_Eta2", &jet_Eta2);
   tuple->SetBranchAddress("jet_Eta3", &jet_Eta3);
   tuple->SetBranchAddress("jet_Eta4", &jet_Eta4);
   tuple->SetBranchAddress("jet_btag1", &jet_btag1);
   tuple->SetBranchAddress("jet_btag2", &jet_btag2);
   tuple->SetBranchAddress("jet_btag3", &jet_btag3);
   tuple->SetBranchAddress("jet_btag4", &jet_btag4);
   tuple->SetBranchAddress("iso04", &iso04);
//   tuple->SetBranchAddress("Mistag_Rate_2b", &Mistag_Rate_2b);
}


double QCD_SF_by_eta(double eta, double nbtags){

    double QCD_SF;

        if(eta<-2.5){
        cout << "Error QCD_SF_by_eta" << endl;
        return -999;
        }

   if(nbtags==1){
	if(eta<-2.0) QCD_SF = 2.73814;
	else if(eta<-1.5) QCD_SF = 2.4045;
	else if(eta<0) QCD_SF = 1.49469;
	else if(eta<1.5) QCD_SF = 1.58987;
	else if(eta<2.0) QCD_SF = 2.3792;
	else if(eta<2.5) QCD_SF = 2.77988;

   }
   else if(nbtags==2){
	if(eta<-2.0) QCD_SF = 1.46519;
	else if(eta<-1.5) QCD_SF = 2.73189;
	else if(eta<0) QCD_SF = 1.95712;
	else if(eta<1.5) QCD_SF = 1.67552;
	else if(eta<2.0) QCD_SF = 1.70839;
	else if(eta<2.5) QCD_SF = 1.12857;
   }
	 else if(nbtags>=3){
	if(eta<-2.0) QCD_SF = 5.29399;
	else if(eta<-1.5) QCD_SF = 2.76316;
	else if(eta<0) QCD_SF = 0.873518;
	else if(eta<1.5) QCD_SF = 0.472443;
	else if(eta<2.0) QCD_SF = 2.55759;
	else if(eta<2.5) QCD_SF = 1.16601;
   }



return QCD_SF;

}




