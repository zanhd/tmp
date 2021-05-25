int BinarySearch(int x, vector<int> a, int beg, int end)
{
	while (beg <= end)
	{
		int mid = (beg + end) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] < x) beg = mid + 1;
		else end = mid - 1;
	}
	return -1;
}

vector<int> findSongs(int rideduration, vector<int> songDuration)
{
	vector<int> ans(2, -1);
	sort(songDuration.begin(), songDuration.end());

	for (int i = 0; i < songDuration.size() - 1; i++)
	{
		int need = rideduration - 30 - songDuration[i];
		int j = BinarySearch(need, songDuration, i + 1, songDuration.size() - 1);
		if (j == -1) continue;
		ans[0] = songDuration[i];
		ans[1] = songDuration[j];
		break;
	}

	return ans;
}
