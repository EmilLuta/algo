import json
import sys


class Photo:
    def __init__(self, i, photo_line):
        photo_line = photo_line.split(' ')
        self.id = i
        self.orientation = photo_line[0]
        self.no_tags = int(photo_line[1])
        self.tags = set(photo_line[1:])

    def __repr__(self):
        return json.dumps({
            "id": self.id,
            "orientation": self.orientation,
            "no_tags": self.no_tags,
            "tags": list(self.tags)
        })

    def score(self, photo):
        common_tags = len(photo.tags.intersection(self.tags))
        return min(self.no_tags - common_tags, common_tags, photo.no_tags - common_tags)

    def merge(self, photo):
        new_photo = Photo()
        new_photo.id = "{} {}".format(self.id, photo.id)
        new_photo.orientation = "H"
        union = self.tags.union(photo.tags)
        new_photo.no_tags(len())
        new_photo.tags = union
        return new_photo


# Read from file
def read_from_file(file_name):
    with open(file_name, "r") as in_file:
        data = in_file.read().strip().split('\n')
        no_photos = int(data[0])
        v_photos = []
        photos = []
        for i in range(no_photos):
            photo = Photo(i, data[i + 1])
        if photo.orientation == "H":
            photos.append(photo)
        if photo.orientation == "V":
            v_photos.append(photo)

        # photos.extend(group_vertical_photos_strategy_A(v_photos))

        return no_photos, photos


def group_vertical_photos_strategy_A(vertical_photos):
    groups = []
    while vertical_photos:
        current = vertical_photos.pop()
        best_n = None
        best_score = -1
        counter = 0
        for photo in vertical_photos:
            m = len(photo.tags.intersection(current.tags))
            if m > best_score:
                best_score = m
                best_n = counter
            counter += 1
        neighbour = vertical_photos.pop(best_n)
        groups.append(current.merge(neighbour))

    return groups

def write_to_output(file_name, no_slides, slides):
    with open(file_name, "w+") as out_file:
        out_file.write(str(no_slides) + "\n")
        for i in range(no_slides):
            out_file.write(" ".join(str(x) for x in slides[i]))
            if i < no_slides - 1:
                out_file.write("\n")


if __name__ == "__main__":
    in_file_name = sys.argv[1]
    out_file_name = "{}.out".format(in_file_name.split('.')[0])
    no_photos, photos = read_from_file(in_file_name)

    import code
    code.interact(local=locals())


    queue = [0]
    output = []
    while queue:
        maximum = 0
        maximum_j = None
        i = queue.pop(0)
        output.append(i)
        for j in range(no_photos):
            if i == j or photos[i] is None or photos[j] is None:
                continue
            current = photos[i].score(photos[j])
            if maximum < current:
                maximum = current
                maximum_j = j
        photos[i] = None
        print(len(output))
        if len(output) % 1000 == 0:
            print('{}/{}'.format(len(output), no_photos))
        if maximum_j is not None:
            queue.append(maximum_j)
    try:
        with open('random.txt', "w+") as f:
            f.write(json.dumps(output))
    except:
        print("errored")
    write_to_output(out_file_name, len(output), [[i] for i in output])
    # write_to_output(out_file_name, 2, [[1, 2], [0]])
