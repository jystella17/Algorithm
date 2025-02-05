// BOJ 8184 Guilds (G5)
// POI (Polish Olympiad in Informatics) 2009/2010

#include <iostream>
#include <vector>
using namespace std;

// Save which guild's office exist in each town
int guild[200001];
vector<vector<int>> towns(200001);

void find_offices(int current){
    for(int i=0; i<towns[current].size(); i++){
        int next = towns[current][i];

        // check if the next town has already been visited
        if(guild[next] > 0) continue;

        // If current town has The Tailors Guild's office => Next adjacent town is likely to have The Sewers Guild's office
        // Because each town can have an office of the guild, or be directly connected to another town that does.
        if(guild[current] == 1)
            guild[next] = 2;

        // If current town has The Sewers Guild's office => Next adjacent town is likely to have The Tailors Guild's office
        else if(guild[current] == 2)
            guild[next] = 1;
            
        find_offices(next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    bool rule = true;
    int n, m; cin>>n>>m;
  
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        towns[a].push_back(b);
        towns[b].push_back(a);
    }

    // Because the given graph is separated into many subgroups, 
    // Every node(town) should be regarded as a starting node of a subgroup
    for(int i=1; i<=n; i++){
        // If current town has already been visited, then it cannot be the starting node of any single subgroup.
        if(guild[i] > 0) continue;

        // If current town is a starting node of a certain subgroup but doesn't have any connected node
        // Then offices cannot be placed following the rule (NIE)
        // Because both TTG and TSG should place their office in this town.
        // (Otherwise, the statement "be directly connected to another town that has office" does not establish.)
        if(towns[i].size() == 0){
            rule = false;
            break;
        }

        // If current town is a starting node of a certain subgroup, build TTG's office in current town
        // and start dfs
        guild[i] = 1;
        find_offices(i);
    }
    
    if(rule){
        cout<<"TAK"<<"\n";
        for(int i=1; i<=n; i++){
            if(guild[i] == 1) cout<<"K"<<"\n";
            else if(guild[i] == 2) cout<<"S"<<"\n";
            else cout<<"N"<<"\n";
        }
    }
    
    else cout<<"NIE"<<"\n";
    
    return 0;
}
