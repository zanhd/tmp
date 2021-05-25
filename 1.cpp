
#include<bits/stdc++.h>
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define FreOpen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define bigint int64_t
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e18
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define vect vector<int>
#define pair_int pair<int,int>
#define paircout(x) cout<<"{"<<(x).first<<" "<<(x).second<<"}";
#define maxheap(T) priority_queue<T>
#define minheap(T) priority_queue<T,vector<T>,greater<T>>
#define mapofvector map<int,vector<int>>
#define mapofset map<int,set<int>>
#define Matrix(type) vector<vector<type>>
#define loop(i,a,b) for(ll i = a; i <= b; i++)
#define rloop(i,a,b) for(ll i = a; i >= b; i--)
#define loopSTL(itr,STL) for (auto itr = STL.begin(); itr != STL.end(); ++itr)
#define sq(a) (a)*(a)
#define NextPermutationSTL(STL) next_permutation(STL.begin(), STL.end())
#define NextPermutation(a,size) next_permutation(a,a+size)
//string tranform
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define lexcompare(str1,size1,str2,size2) lexicographical_compare(str1, str1+size1, str2, str2+size2)
//Modular Arthematics
#define MOD ((ll) 1e9 + 7)
#define MOD2 ((ll) 1e9 + 9)
#define ModAdd(a,b,N) 		((a)%(N) + (b)%(N))%(N);
#define ModSub(a,b,N) 		((a)%(N) - (b)%(N))%(N);
#define ModMultiply(a,b,N)	((a)%(N) * (b)%(N))%(N);
//extra
#define ceil_div(a,b) (a+b-1)/(b)
#define gcd(a,b) __gcd((long long int) a,(long long int) b)
using namespace std;

struct Song
{
	int id;
	int dur;
};

int BinarySearch(int x, vector<Song> a, int beg, int end)
{
	while (beg <= end)
	{
		int mid = (beg + end) / 2;
		if (a[mid].dur == x) return mid;
		if (a[mid].dur < x) beg = mid + 1;
		else end = mid - 1;
	}
	return -1;
}

vector<int> findSongs(int rideduration, vector<int> songDuration)
{
	vector<int> ans(2, -1);

	vector<Song> songs(songDuration.size());
	for (int i = 0; i < songDuration.size(); i++)
	{
		songs[i].id = i;
		songs[i].dur = songDuration[i];
	}

	sort(songs.begin(), songs.end(), [](Song a, Song b) { return a.dur < b.dur; });

	for (int i = 0; i < songDuration.size() - 1; i++)
	{
		int need = rideduration - 30 - songs[i].dur;
		int j = BinarySearch(need, songs, i + 1, songDuration.size());
		if (j == -1) continue;
		ans[0] = songs[i].id;
		ans[1] = songs[j].id;
		break;
	}

	return ans;
}

void Solve()
{
	int d; cin >> d;

	int n; cin >> n;
	vector<int> a(n); loop(i, 0, n - 1) cin >> a[i];

	for (auto x : findSongs(d, a)) cout << x << " ";

}

int main(int argc, char const *argv[])
{

	FastIO;
	//FreOpen;
	int T = 1;
	//cin >> T;
	while (T--) Solve();
	return 0;
}
