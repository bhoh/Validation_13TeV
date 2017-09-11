#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TPad.h"
#include "fstream.h"

   //global variables
   double Trigger_SF, Trigger_SF_UP, Trigger_SF_DOWN, MuonTrack_SF, Muon_SF, Muon_SF_UP, Muon_SF_DOWN, MuonISO_SF, MuonISO_SF_UP, MuonISO_SF_DOWN;
   double weight_by_trigger, weight, MCweight, PU, PU_UP, PU_DOWN, BTag_SF;
   double nbtags, nVer, njets, Mu_Pt, Mu_Eta, METv, jet_Pt1, jet_Pt2, jet_Pt3, jet_Pt4, jet_Eta1, jet_Eta2, jet_Eta3, jet_Eta4;
   double jet_btag1, jet_btag2, jet_btag3, jet_btag4;
   double iso04;
   
//main function
void Validation_13TeV_QCD(){



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

   TH1F *h_TT_QCD_1b =new TH1F("h_TT_QCD_1b", "h_TT_QCD_1b", 25, 0,0.25);    h_TT_QCD_1b ->Sumw2();
   TH1F *h_TT_QCD_2b =new TH1F("h_TT_QCD_2b", "h_TT_QCD_2b", 25, 0,0.25);    h_TT_QCD_2b ->Sumw2();
   TH1F *h_TT_QCD_3b =new TH1F("h_TT_QCD_3b", "h_TT_QCD_3b", 25, 0,0.25);    h_TT_QCD_3b ->Sumw2();
   TH1F *h_VJ_QCD_1b =new TH1F("h_VJ_QCD_1b", "h_VJ_QCD_1b", 25, 0,0.25);    h_VJ_QCD_1b ->Sumw2();
   TH1F *h_VJ_QCD_2b =new TH1F("h_VJ_QCD_2b", "h_VJ_QCD_2b", 25, 0,0.25);    h_VJ_QCD_2b ->Sumw2();
   TH1F *h_VJ_QCD_3b =new TH1F("h_VJ_QCD_3b", "h_VJ_QCD_3b", 25, 0,0.25);    h_VJ_QCD_3b ->Sumw2();
   TH1F *h_ST_QCD_1b =new TH1F("h_ST_QCD_1b", "h_ST_QCD_1b", 25, 0,0.25);    h_ST_QCD_1b ->Sumw2();
   TH1F *h_ST_QCD_2b =new TH1F("h_ST_QCD_2b", "h_ST_QCD_2b", 25, 0,0.25);    h_ST_QCD_2b ->Sumw2();
   TH1F *h_ST_QCD_3b =new TH1F("h_ST_QCD_3b", "h_ST_QCD_3b", 25, 0,0.25);    h_ST_QCD_3b ->Sumw2();
   TH1F *h_VV_QCD_1b =new TH1F("h_VV_QCD_1b", "h_VV_QCD_1b", 25, 0,0.25);    h_VV_QCD_1b ->Sumw2();
   TH1F *h_VV_QCD_2b =new TH1F("h_VV_QCD_2b", "h_VV_QCD_2b", 25, 0,0.25);    h_VV_QCD_2b ->Sumw2();
   TH1F *h_VV_QCD_3b =new TH1F("h_VV_QCD_3b", "h_VV_QCD_3b", 25, 0,0.25);    h_VV_QCD_3b ->Sumw2();
   TH1F *h_TTX_QCD_1b =new TH1F("h_TTX_QCD_1b", "h_TTX_QCD_1b", 25, 0,0.25);    h_TTX_QCD_1b ->Sumw2();
   TH1F *h_TTX_QCD_2b =new TH1F("h_TTX_QCD_2b", "h_TTX_QCD_2b", 25, 0,0.25);    h_TTX_QCD_2b ->Sumw2();
   TH1F *h_TTX_QCD_3b =new TH1F("h_TTX_QCD_3b", "h_TTX_QCD_3b", 25, 0,0.25);    h_TTX_QCD_3b ->Sumw2();



   SetBranchAddress(DATA_t, DATA);
   SetBranchAddress(DATA_antiiso_t, DATA_antiiso);

   TH1F *h_DATA_QCD_1b =new TH1F("h_DATA_QCD_1b", "h_DATA_QCD_1b", 25, 0,0.25);	h_DATA_QCD_1b ->Sumw2();
   TH1F *h_DATA_QCD_2b =new TH1F("h_DATA_QCD_2b", "h_DATA_QCD_2b", 25, 0,0.25);	h_DATA_QCD_2b ->Sumw2();
   TH1F *h_DATA_QCD_3b =new TH1F("h_DATA_QCD_3b", "h_DATA_QCD_3b", 25, 0,0.25);	h_DATA_QCD_3b ->Sumw2();

//////////////////////////////////////// QCD_SF ///////////////////////////////////////////////////////

   double xbin[7] = { -2.5, -2.0, -1.5, 0, 1.5, 2.0, 2.5};

   TH1F *QCD_SF_DATA_iso_1b =new TH1F("QCD_SF_DATA_iso_1b", "QCD_SF_DATA_iso_1b", 6, xbin);
   TH1F *QCD_SF_MC_iso_1b =new TH1F("QCD_SF_MC_iso_1b", "QCD_SF_MC_iso_1b", 6, xbin);
   TH1F *QCD_SF_DATA_antiiso_1b =new TH1F("QCD_SF_DATA_antiiso_1b", "QCD_SF_DATA_antiiso_1b", 6, xbin);
   TH1F *QCD_SF_MC_antiiso_1b =new TH1F("QCD_SF_MC_antiiso_1b", "QCD_SF_MC_antiiso_1b", 6, xbin);

   TH1F *QCD_SF_DATA_iso_2b =new TH1F("QCD_SF_DATA_iso_2b", "QCD_SF_DATA_iso_2b", 6, xbin);
   TH1F *QCD_SF_MC_iso_2b =new TH1F("QCD_SF_MC_iso_2b", "QCD_SF_MC_iso_2b", 6, xbin);
   TH1F *QCD_SF_DATA_antiiso_2b =new TH1F("QCD_SF_DATA_antiiso_2b", "QCD_SF_DATA_antiiso_2b", 6, xbin);
   TH1F *QCD_SF_MC_antiiso_2b =new TH1F("QCD_SF_MC_antiiso_2b", "QCD_SF_MC_antiiso_2b", 6, xbin);

   TH1F *QCD_SF_DATA_iso_3b =new TH1F("QCD_SF_DATA_iso_3b", "QCD_SF_DATA_iso_3b", 6, xbin);
   TH1F *QCD_SF_MC_iso_3b =new TH1F("QCD_SF_MC_iso_3b", "QCD_SF_MC_iso_3b", 6, xbin);
   TH1F *QCD_SF_DATA_antiiso_3b =new TH1F("QCD_SF_DATA_antiiso_3b", "QCD_SF_DATA_antiiso_3b", 6, xbin);
   TH1F *QCD_SF_MC_antiiso_3b =new TH1F("QCD_SF_MC_antiiso_3b", "QCD_SF_MC_antiiso_3b", 6, xbin);

//////////////////////////////////////// Fill MC /////////////////////////////////////////////////////
   double Scale =1; 	double Scale_ST = 1;


   for (int i=0; i<1; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut

      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale;               //*36.4466098;
      if(nbtags==1){
           h_TT_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_1b -> Fill(Mu_Eta,weight_SF);
      }
      else if(nbtags==2){
           h_TT_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_TT_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }

   for (int i=1; i<3; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale; //*Trigger_SF*Muon_SF*(MuonISO_SF_UP+MuonISO_SF_DOWN)/2
      if(nbtags==1){
           h_VJ_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_VJ_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_VJ_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }

   for (int i=3; i<10; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale*Scale_ST;
      if(nbtags==1){
           h_ST_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_ST_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_ST_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }

   for (int i=10; i<13; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale*Scale_ST;
      if(nbtags==1){
           h_VV_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_VV_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_VV_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }

   for (int i=13; i<17; i++){
   for (int k=0; k<MC_t[i]->GetEntries(); k++){
   
      MC_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale*Scale_ST;
      if(nbtags==1){
           h_TTX_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_TTX_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_TTX_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_iso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }


   for (int i=0; i<1; i++){
   for (int k=0; k<MC_antiiso_t[i]->GetEntries(); k++){
   
      MC_antiiso_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut

      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale;               //*36.4466098;
      if(nbtags==1){
           h_TT_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_TT_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_TT_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }

   for (int i=1; i<3; i++){
   for (int k=0; k<MC_antiiso_t[i]->GetEntries(); k++){
   
      MC_antiiso_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale; //*Trigger_SF*Muon_SF*(MuonISO_SF_UP+MuonISO_SF_DOWN)/2
      if(nbtags==1){
           h_VJ_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_VJ_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_VJ_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }

   for (int i=3; i<10; i++){
   for (int k=0; k<MC_antiiso_t[i]->GetEntries(); k++){
   
      MC_antiiso_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale*Scale_ST;
      if(nbtags==1){
           h_ST_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_ST_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_ST_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }


   for (int i=10; i<13; i++){
   for (int k=0; k<MC_antiiso_t[i]->GetEntries(); k++){
   
      MC_antiiso_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale*Scale_ST;
      if(nbtags==1){
           h_VV_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_VV_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_VV_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }


   for (int i=13; i<17; i++){
   for (int k=0; k<MC_antiiso_t[i]->GetEntries(); k++){
   
      MC_antiiso_t[i]->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      double weight_SF = weight*MCweight*weight_by_trigger*PU*Trigger_SF*Muon_SF*MuonISO_SF*MuonTrack_SF*BTag_SF*36.4466098*Scale*Scale_ST;
      if(nbtags==1){
           h_TTX_QCD_1b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_1b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags==2){
           h_TTX_QCD_2b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_2b -> Fill(Mu_Eta,weight_SF);

      }
      else if(nbtags>=3){
           h_TTX_QCD_3b -> Fill(iso04,weight_SF);
	   QCD_SF_MC_antiiso_3b -> Fill(Mu_Eta,weight_SF);

      }

   }
   }



//////////////////////////////////////// Fill DATA /////////////////////////////////////////////////////

   for (int k=0; k<DATA_t->GetEntries(); k++){
   
      DATA_t->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut



      if(nbtags==1){
           h_DATA_QCD_1b -> Fill(iso04,1.);
	   QCD_SF_DATA_iso_1b -> Fill(Mu_Eta,1.);

      }
      else if(nbtags==2){
           h_DATA_QCD_2b -> Fill(iso04,1.);
	   QCD_SF_DATA_iso_2b -> Fill(Mu_Eta,1.);

      }
      else if(nbtags>=3){
           h_DATA_QCD_3b -> Fill(iso04,1.);
	   QCD_SF_DATA_iso_3b -> Fill(Mu_Eta,1.);

      }

   }

   for (int k=0; k<DATA_antiiso_t->GetEntries(); k++){
   
      DATA_antiiso_t->GetEntry(k);
      if(Mu_Pt<30) continue; /// Muon selection cut
      if(METv >20) continue; /// MET selection cut
      if(jet_Pt1<30) continue; /// Jet selection cut
      if(jet_Pt2<30) continue; /// Jet selection cut
      if(jet_Pt3<30) continue; /// Jet selection cut
      if(jet_Pt4<30) continue; /// Jet selection cut


      if(nbtags==1){
           h_DATA_QCD_1b -> Fill(iso04,1.);
	   QCD_SF_DATA_antiiso_1b -> Fill(Mu_Eta,1.);

      }
      else if(nbtags==2){
           h_DATA_QCD_2b -> Fill(iso04,1.);
	   QCD_SF_DATA_antiiso_2b -> Fill(Mu_Eta,1.);

      }
      else if(nbtags>=3){
           h_DATA_QCD_3b -> Fill(iso04,1.);
	   QCD_SF_DATA_antiiso_3b -> Fill(Mu_Eta,1.);

      }

   }


////////////////////////// QCD_SF //////////////////////////////////

   QCD_SF_DATA_iso_1b->Add(QCD_SF_MC_iso_1b, -1);
   QCD_SF_DATA_iso_2b->Add(QCD_SF_MC_iso_2b, -1);
   QCD_SF_DATA_iso_3b->Add(QCD_SF_MC_iso_3b, -1);
   QCD_SF_DATA_antiiso_1b->Add(QCD_SF_MC_antiiso_1b, -1);
   QCD_SF_DATA_antiiso_2b->Add(QCD_SF_MC_antiiso_2b, -1);
   QCD_SF_DATA_antiiso_3b->Add(QCD_SF_MC_antiiso_3b, -1);

   QCD_SF_DATA_iso_1b->Divide(QCD_SF_DATA_antiiso_1b);
   QCD_SF_DATA_iso_2b->Divide(QCD_SF_DATA_antiiso_2b);
   QCD_SF_DATA_iso_3b->Divide(QCD_SF_DATA_antiiso_3b);

//////////////////////////////////////// Stack ////////////////////////////////////////////////////////

  THStack *hs_MC_QCD_1b= new THStack("hs_QCD_1b","hs_QCD_1b");
  THStack *hs_MC_QCD_2b= new THStack("hs_QCD_2b","hs_QCD_2b");
  THStack *hs_MC_QCD_3b= new THStack("hs_QCD_3b","hs_QCD_3b");
h_TT_QCD_1b->SetLineColor(kRed);      h_TT_QCD_1b->SetFillColor(kRed);
h_TT_QCD_2b->SetLineColor(kRed);      h_TT_QCD_2b->SetFillColor(kRed);
h_TT_QCD_3b->SetLineColor(kRed);      h_TT_QCD_3b->SetFillColor(kRed);

h_ST_QCD_1b->SetLineColor(kMagenta);      h_ST_QCD_1b->SetFillColor(kMagenta);
h_ST_QCD_2b->SetLineColor(kMagenta);      h_ST_QCD_2b->SetFillColor(kMagenta);
h_ST_QCD_3b->SetLineColor(kMagenta);      h_ST_QCD_3b->SetFillColor(kMagenta);

h_VJ_QCD_1b->SetLineColor(kOrange);      h_VJ_QCD_1b->SetFillColor(kOrange);
h_VJ_QCD_2b->SetLineColor(kOrange);      h_VJ_QCD_2b->SetFillColor(kOrange);
h_VJ_QCD_3b->SetLineColor(kOrange);      h_VJ_QCD_3b->SetFillColor(kOrange);

  hs_MC_QCD_1b->Add(h_TT_QCD_1b);
  hs_MC_QCD_2b->Add(h_TT_QCD_2b);
  hs_MC_QCD_3b->Add(h_TT_QCD_3b);
  hs_MC_QCD_1b->Add(h_ST_QCD_1b);
  hs_MC_QCD_2b->Add(h_ST_QCD_2b);
  hs_MC_QCD_3b->Add(h_ST_QCD_3b);
  hs_MC_QCD_1b->Add(h_VJ_QCD_1b);
  hs_MC_QCD_2b->Add(h_VJ_QCD_2b);
  hs_MC_QCD_3b->Add(h_VJ_QCD_3b);


///////////////////////

gStyle->SetOptStat(0);

	TCanvas *c1 = new TCanvas("c1", "", 800, 600);    // Canvas

        c1 -> cd();
	hs_MC_QCD_1b->Draw("hist");


//        h_DATA_QCD_1b->GetYaxis()->SetLogy();
	h_DATA_QCD_1b->SetMarkerStyle(20); //"20" means the shape of signs is a circle
	h_DATA_QCD_1b->SetMarkerSize(1.);  //size of the signs
        h_DATA_QCD_1b->Draw("epsame");
        TLine *line = new TLine(0.15,0,0.15,25000);
        line->SetLineStyle(3);
        line->Draw();
				

     c1->SaveAs("hs_QCD_iso_1b.png");

////////////////////////

	TCanvas *c2 = new TCanvas("c2", "", 800, 600);    // Canvas
        c2 -> cd();

	QCD_SF_DATA_iso_1b->Draw("hist");


     c2->SaveAs("hs_QCD_1b.png");
//////////////////////////
	TCanvas *c3 = new TCanvas("c3", "", 800, 600);    // Canvas
        c3 -> cd();

	QCD_SF_DATA_iso_2b->Draw("hist");

				

     c3->SaveAs("hs_QCD_2b.png");
//////////////////////////
	TCanvas *c4 = new TCanvas("c4", "", 800, 600);    // Canvas
        c4 -> cd();

	QCD_SF_DATA_iso_3b->Draw("hist");

				

     c4->SaveAs("hs_QCD_3b.png");

////////////////////////////// QCD_SF file creation //////////////////////////

         ofstream fout("QCD_SF.cpp");

         fout << QCD_SF_DATA_iso_1b->GetBinContent(1) <<";"<< endl;
         fout << QCD_SF_DATA_iso_1b->GetBinContent(2) <<";"<< endl;
         fout << QCD_SF_DATA_iso_1b->GetBinContent(3) <<";"<< endl;
         fout << QCD_SF_DATA_iso_1b->GetBinContent(4) <<";"<< endl;
         fout << QCD_SF_DATA_iso_1b->GetBinContent(5) <<";"<< endl;
         fout << QCD_SF_DATA_iso_1b->GetBinContent(6) <<";"<< endl;
 

	 fout << endl << endl;

         fout << QCD_SF_DATA_iso_2b->GetBinContent(1) <<";"<< endl;
         fout << QCD_SF_DATA_iso_2b->GetBinContent(2) <<";"<< endl;
         fout << QCD_SF_DATA_iso_2b->GetBinContent(3) <<";"<< endl;
         fout << QCD_SF_DATA_iso_2b->GetBinContent(4) <<";"<< endl;
         fout << QCD_SF_DATA_iso_2b->GetBinContent(5) <<";"<< endl;
         fout << QCD_SF_DATA_iso_2b->GetBinContent(6) <<";"<< endl;

	 fout << endl << endl;

         fout << QCD_SF_DATA_iso_3b->GetBinContent(1) <<";"<< endl;
         fout << QCD_SF_DATA_iso_3b->GetBinContent(2) <<";"<< endl;
         fout << QCD_SF_DATA_iso_3b->GetBinContent(3) <<";"<< endl;
         fout << QCD_SF_DATA_iso_3b->GetBinContent(4) <<";"<< endl;
         fout << QCD_SF_DATA_iso_3b->GetBinContent(5) <<";"<< endl;
         fout << QCD_SF_DATA_iso_3b->GetBinContent(6) <<";"<< endl;


         fout.close();

}

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

}






