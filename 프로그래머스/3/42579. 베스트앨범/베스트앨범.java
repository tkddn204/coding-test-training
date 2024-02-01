import java.util.*;
import java.util.stream.Collectors;

class Solution {
    class Song implements Comparable<Song> {
        int num;
        String genre;
        int play;

        Song(int num, String genre, int play) {
            this.num = num;
            this.genre = genre;
            this.play = play;
        }

        public int compareTo(Song s) {
            if (this.play == s.play) {
                return Integer.compare(this.num, s.num);
            }
            return Integer.compare(s.play, this.play);
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> gc = new HashMap<>();
        Map<String, List<Song>> songGroups = new HashMap<>();

        for (int i = 0; i < genres.length; i++) {
            gc.put(genres[i], gc.getOrDefault(genres[i], 0) + plays[i]);
            if (!songGroups.containsKey(genres[i])) {
                songGroups.put(genres[i], new ArrayList<>());
            }
            songGroups.get(genres[i]).add(new Song(i, genres[i], plays[i]));
        }

        List<String> sg = gc.entrySet().stream()
            .sorted((a, b) -> b.getValue().compareTo(a.getValue()))
            .map(Map.Entry::getKey)
            .collect(Collectors.toList());

        List<Integer> answer = new ArrayList<>();
        for (String genre : sg) {
            List<Song> sortedSongs = songGroups.get(genre).stream().sorted().collect(Collectors.toList());
            answer.add(sortedSongs.get(0).num);
            if (sortedSongs.size() > 1) {
                answer.add(sortedSongs.get(1).num);
            }
        }

        return answer.stream().mapToInt(i -> i).toArray();
    }
}