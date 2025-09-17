#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int distEdProgDina(std::string s1, std::string s2)
{
    int m = s1.size();
    int n = s2.size();
    std::vector<std::vector<int>> matriz(m, std::vector<int>(n, 0));
    matriz[0][0] = 0;
    for (int i = 1; i < m; i++)
    {
        matriz[i][0] = i;
    }
    for (int i = 1; i < n; i++) 
    {
        matriz[0][i] = i;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int custoExtra = -1;
            if (s1.at(i) == s2.at(j))
            {
                custoExtra = 0;
            }
            else 
            {
                custoExtra = 1;
            }
            matriz[i][j] = std::min(
                {
                    matriz[i-1][j] + 1,
                    matriz[i][j-1] + 1,
                    matriz[i-1][j-1] + custoExtra 
                }
            );
        }
    }
    return matriz[m-1][n-1];
}


int main(int argc, char const *argv[])
{
    std::string s1 = "Casablanca";
    std::string s2 = "Portentoso";
    std::string s3 = "Maven, a Yiddish word meaning accumulator of knowledge, began as an attempt to simplify the build processes in the Jakarta Turbine project. There were several projects, each with their own Ant build files, that were all slightly different. JARs were checked into CVS. We wanted a standard way to build the projects, a clear definition of what the project consisted of, an easy way to publish project information and a way to share JARs across several projects. The result is a tool that can now be used for building and managing any Java-based project. We hope that we have created something that will make the day-to-day work of Java developers easier and generally help with the comprehension of any Java-based project.";
    std::string s4 = "This post is not about deep learning. But it could be might as well. This is the power of kernels. They are universally applicable in any machine learning algorithm. Why you might ask? I am going to try to answer this question in this article. Go to the profile of Marin Vlastelica Pogančić Marin Vlastelica Pogančić Jun";

    std::cout << "resultado 1: " << distEdProgDina(s1,s2) << "\n" << 
    "resultado 2: " << distEdProgDina(s1,s3) << "\n" << 
    "resultado 3: " << distEdProgDina(s3,s4) << "\n";    
    return 0;
}
