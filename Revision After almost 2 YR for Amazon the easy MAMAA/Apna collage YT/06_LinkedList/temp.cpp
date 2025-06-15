#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pi pair<int,int>
#define mi map<int,int>
#define umi unordered_map<int,int>
#define qi queue<int>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff first
#define ss second 
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;

void printBinary(int n){
    for(int i=10;i>=0;i--){
        if((n>>i) & 1) cout << 1;
        else cout << 0;
    }cout << endl;
}

class node{
    public:
        int val;
        node* next;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            left = NULL;
            right = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>
#define tag_t int;


vector<int> adj[N];
bool vis[N];


int32_t main(){

    tag_t topItem;
    tag_t newBomWindow;
    tag_t appSession;

    std::vector<std::pair<std::string, tag_t>> stableIdVsBomLine;
    std::vector< int > errors;
    tag_t revisionRule;
    std::string stableId;

    // get stable ids from app session
    APPSESSION_get_all_structures(appSession, stableIdVsBomLine);

    // get previous revision rule
    BOM_ask_window_config_rule(stableIdVsBomLine[0].second, &revisionRule);

    // remove previous structure 
    std::vector< std::string > stableIds{ stableIdVsBomLine[0].first };
    APPSESSION_remove_structures_and_contents_by_stableids(appSession, stableIds, errors);
    
    // set revision rule on new window 
    BOM_set_window_config_rule(newBomWindow, revisionRule);
    
    // add new bom window on appSession
    APPSESSION_add_structure(appSession, newBomWindow, PersistMode::DO_NOT_PERSIST_RESULTS, stableId);
}

void changeRevisionRuleOfContainerFromSpec(std::vector<ContainerS>& vecModelInfoS){
    for(auto& container: vecModelInfoS){
        string type = container.containerType;
        if(type == "Requirement spec"){
            string uid = container.tcOriginalContainerUid;
            tag_t containerTag;
            BOREG_uid_to_tag( uid.c_str(), &containerTag );
            tag_t specTag = getItemFromItemRev(containerTag);

            tag_t appSession;
            AOM_ask_value_tag( specTag, "cus5fnd0AppSession", &appSession );

            if(appSession != NULLTAG){    
                std::vector<std::pair<std::string, tag_t>> stableIdVsBomLine;
                APPSESSION_get_all_structures(appSession, stableIdVsBomLine);

                // use this step if we get the our revusion rule
                tag_t revRule;
                BOM_ask_window_config_rule(stableIdVsBomLine[0].second, &revRule);
                // 0r
                // the code we already have to retrive the revison rule

                CFM_Revision_Rule_Info2 revisionRuleInfo;
                scoped_smptr<char> revisionRuleUid;
                ResultStatus stat =   ( revRule, &revisionRuleUid );
                CFM_get_revision_rule_info( revisionRuleUid.getString(), revisionRuleInfo );

                string revRuleName = revisionRuleInfo.name;

                // update the revision rule in the container.
                container.userInputsMap["Revision rule"] = revRuleName;
                // or
                // skip the above code and just do 
                // container.userInputsMap["Revision rule"] = "Polarion Reuse";

                for(auto& stableIdVsBomPair : stableIdVsBomLine){
                    BOM_close_window( stableIdVsBomPair.second );
                }
            }
        }
    }
}

// way 2
{

    std::vector<ContainerS> vecModelInfoS; // as a input to the function.

    for(auto& container: vecModelInfoS){
        string type = container.containerType;
        if(type == "Requirement spec"){
            string uid = container.tcOriginalContainerUid;
            tag_t containerTag;
            BOREG_uid_to_tag( uid.c_str(), &containerTag );
            tag_t specTag = getItemFromItemRev(containerTag);

            tag_t appSession;
            AOM_ask_value_tag( specTag, "cus5fnd0AppSession", &appSession );

            if(appSession != NULLTAG){    
                std::vector<std::pair<std::string, tag_t>> stableIdVsBomLine;
                APPSESSION_get_all_structures(appSession, stableIdVsBomLine);

                // use this step if we get the our revusion rule
                tag_t revRule;
                BOM_ask_window_config_rule(stableIdVsBomLine[0].second, &revRule);
                // 0r
                // the code we already have to retrive the revison rule

                CFM_Revision_Rule_Info2 revisionRuleInfo;
                scoped_smptr<char> revisionRuleUid;
                ResultStatus stat = BOREG_tag_to_uid( revRule, &revisionRuleUid );
                CFM_get_revision_rule_info( revisionRuleUid.getString(), revisionRuleInfo );

                string revRuleName = revisionRuleInfo.name;

                // update the revision rule in the container.
                container.userInputsMap["Revision rule"] = revRuleName;
                // or
                // skip the above code and just do 
                // container.userInputsMap["Revision rule"] = "Polarion Reuse";

                for(auto& stableIdVsBomPair : stableIdVsBomLine){
                    BOM_close_window( stableIdVsBomPair.second );
                }
            }
        }
    }


}