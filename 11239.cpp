#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<string>
#include<map>
#include<vector>

char line[100000];
int signs, project_index;

class project {
public:
  std::string name;
  std::set<std::string> students;
  int member_count; //the effective one.

  explicit project(const char* project_name) : name(project_name) {};

  inline void add_member(const std::string& student) { students.insert(student); }
  inline bool operator < (const project& other) const {
    if(member_count==other.member_count)
      return std::lexicographical_compare(name.begin(), name.end(), other.name.begin(), other.name.end());
    else
      return member_count > other.member_count;
  }
};

int main() {
  std::vector<project> projects;
  std::map<std::string, std::set<std::string> > student_signs;
  std::set<std::string>::const_iterator s_it;

  projects.reserve(100);

  while(gets(line)!=NULL) {
    if(line[0]=='0') break;
    else if(isupper(line[0])) {
      projects.push_back(project(line));
      project_index = projects.size() - 1;
    } else if(line[0]!='1') { //student name
      std::string student_name(line);
      projects[project_index].add_member(student_name);
      student_signs[student_name].insert(projects[project_index].name);
    } else {  //end of test case. print.
      for(std::vector<project>::iterator p_it = projects.begin(); p_it!=projects.end(); ++p_it) {
	const std::set<std::string>& members = p_it->students;
	signs = members.size();
	for(s_it = members.begin(); s_it != members.end(); ++s_it) {
          if(student_signs[*s_it].size()>1) --signs;
	}
	p_it->member_count = signs;
      }

      std::stable_sort(projects.begin(), projects.end());
      for(std::vector<project>::const_iterator v_it = projects.begin(); v_it!=projects.end(); ++v_it) {
        printf("%s %d\n", v_it->name.c_str(), v_it->member_count);
      }

      projects.clear();
      student_signs.clear();
    }
  }
}
