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
		int j = BinarySearch(need, songs, i + 1, songDuration.size() - 1);
		if (j == -1) continue;
		ans[0] = songs[i].id;
		ans[1] = songs[j].id;
		break;
	}
	
	sort(ans.begin(),ans.end()); //extra line
		
	return ans;
}
