#include<string>
#include<iostream>
#include<algorithm>

int ed(std::string s1, std::string s2, int indx1, int indx2)
{
    if (0 == indx1) return indx2;
    if (0 == indx2) return indx1;
    //std::cout << s1.at(indx1) << " " << s2.at(indx1) << "\n";
    if (s1.at(indx1) == s2.at(indx2)) return ed(s1,s2,indx1-1,indx2-1);

    int a = ed(s1,s2,indx1-1,indx2-1) + 1;
    int b = ed(s1,s2,indx1,indx2-1) + 1;
    int c = ed(s1,s2,indx1-1,indx2) + 1;
    //std::cout << "" << a << " " << b << " " << c << "\n";
    return std::min(
        {
            a,b,c
        }
    );

} 

int main(int argc, char const *argv[])
{
    std::string s1 = "Casablanca";
    std::string s2 = "Portentoso";
    std::string s3 = "Maven, a Yiddish word meaning accumulator of knowledge, began as an attempt to simplify the build processes in the Jakarta Turbine project. There were several projects, each with their own Ant build files, that were all slightly different. JARs were checked into CVS. We wanted a standard way to build the projects, a clear definition of what the project consisted of, an easy way to publish project information and a way to share JARs across several projects. The result is a tool that can now be used for building and managing any Java-based project. We hope that we have created something that will make the day-to-day work of Java developers easier and generally help with the comprehension of any Java-based project.";
    std::string s4 = "This post is not about deep learning. But it could be might as well. This is the power of kernels. They are universally applicable in any machine learning algorithm. Why you might ask? I am going to try to answer this question in this article. Go to the profile of Marin Vlastelica Pogančić Marin Vlastelica Pogančić Jun";
    std::cout << "resultado 1: " << ed(s1,s2,s1.size()-1,s2.size()-1) << "\n" << 
    "resultado 2: " << ed(s1,s3,s1.size()-1,s3.size()-1) << "\n" << 
    "resultado 3: " << ed(s3,s4,s3.size()-1,s4.size()-1) << "\n";
    return 0;
}
