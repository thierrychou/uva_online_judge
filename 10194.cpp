#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
#include<vector>

bool first_set;
int i, n, t, g;
char line[1000];
char tour_name[101];

class Team {
public:
  std::string team_name;
  int points;
  int total, wins, losses, ties;
  int goals_scored, goals_against;

  Team(const char* name)
	  : team_name(name),
	  points(0), total(0), wins(0), losses(0), ties(0),
	  goals_scored(0), goals_against(0)
  {
  }

  //FIXME: can be faster.
  inline bool operator < (const Team& other) const {
    if(points != other.points) return points > other.points;
    if(wins != other.wins) return wins > other.wins;
    int diff = goals_scored - goals_against;
    int diff_other = other.goals_scored - other.goals_against;
    if(diff != diff_other) return diff > diff_other;
    if(goals_scored != other.goals_scored) return goals_scored > other.goals_scored;
    if(total != other.total) return total < other.total;
    return strcasecmp(team_name.c_str(), other.team_name.c_str()) < 0;
  }
};

int main() {
  first_set = true;
  std::map<std::string, int> team_index;
  std::vector<Team> teams;
  teams.reserve(30);

  scanf("%d\n", &n);
  while(n--) {
    //init.
    team_index.clear();
    teams.clear();

    gets(tour_name);
    if(first_set) {
      printf("%s\n", tour_name);
      first_set = false;
    } else {
      printf("\n%s\n", tour_name);
    }

    scanf("%d\n", &t);
    for(i=0; i<t; ++i) {
      gets(line);
      team_index[std::string(line)] = i;
      teams.push_back(Team(line));
    }

    //read results.
    scanf("%d\n", &g);
    while(g--) {
      gets(line);
      char* first_part = strtok(line, "@");
      char* second_part = strtok(NULL, "@");
      char* team_a = strtok(first_part, "#");
      int   goal_a = atoi(strtok(NULL, "#"));
      int   goal_b = atoi(strtok(second_part, "#"));
      char* team_b = strtok(NULL, "#");

      Team& a = teams[team_index[std::string(team_a)]];
      Team& b = teams[team_index[std::string(team_b)]];

      a.total++;
      b.total++;
      a.goals_scored += goal_a;
      a.goals_against += goal_b;
      b.goals_scored += goal_b;
      b.goals_against += goal_a;
      if(goal_a>goal_b) {
	a.points += 3;
	a.wins++;
	b.losses++;
      } else if(goal_a==goal_b) {
        a.points++;
	b.points++;
	a.ties++;
	b.ties++;
      } else {
      	b.points += 3;
	b.wins++;
	a.losses++;
      }
    }
    std::sort(teams.begin(), teams.end());

    for(i=1;i<=t;++i) {
      const Team& team = teams[i-1];
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
		      i,
		      team.team_name.c_str(),
		      team.points,
		      team.total,
		      team.wins,
		      team.ties,
		      team.losses,
		      team.goals_scored - team.goals_against,
		      team.goals_scored,
		      team.goals_against);
    }
  }
  return 0;
}
