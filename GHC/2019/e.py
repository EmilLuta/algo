import json
import sys


class Photo:
    def __init__(self, i, photo_line):
        photo_line = photo_line.split(' ')
        self.id = i
        self.orientation = photo_line[0]
        self.no_tags = int(photo_line[1])
        self.tags = set(photo_line[2:])

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
        new_id = "{} {}".format(self.id, photo.id)
        new_orientation = "H"
        new_union = self.tags.union(photo.tags)
        self.id = new_id
        self.orientation = new_orientation
        self.no_tags = len(new_union)
        self.tags = new_union
        return self

# Read from file
def read_from_file(file_name):
    with open(file_name, "r") as in_file:
        data = in_file.read().strip().split('\n')
        no_photos = int(data[0])
        v_photos = []
        photos = []
        for i in range(no_photos):
            photo = Photo(str(i), data[i + 1])
            if photo.orientation == "H":
                photos.append(photo)
            if photo.orientation == "V":
                v_photos.append(photo)
        photos.extend(group_vertical_photos_strategy_B(v_photos))

        return photos


def write_to_output(file_name, no_slides, slides):
    with open(file_name, "w+") as out_file:
        out_file.write(str(no_slides) + "\n")
        for i in range(no_slides):
            out_file.write(" ".join(str(x) for x in slides[i]))
            if i < no_slides - 1:
                out_file.write("\n")


def group_vertical_photos_strategy_A(v_photos):

    photos = []
    for i in range(len(v_photos)):
        if v_photos[i] is None:
            continue
        maximum = 0
        maximum_j = 0
        for j in range(len(v_photos)):
            if j == i or v_photos[j] is None:
                continue
            current = len(v_photos[i].tags.union(v_photos[j].tags)
)
            if current > maximum:
                maximum = current
                maximum_j = j
        photos.append(v_photos[i].merge(v_photos[maximum_j]))
        v_photos[i] = None
        v_photos[maximum_j] = None

    return photos

def group_vertical_photos_strategy_B(v_photos):
    photos = []
    v_photos = sorted(photos, key=lambda x: x.no_tags)
    for i in range(0, len(v_photos), 2):
        photos.append(v_photos[i].merge(v_photos[i + 1]))
    return photos

def group_horizontal_photos_strategy_D(photos):
    tags = {}
    d_photos = {}
    for photo in photos:
        d_photos[photo.id] = photo
        for tag in photo.tags:
            tags.setdefault(tag, [])
            tags[tag].append(photo.id)
    queue = [photos[0].id]
    visited = set()
    output = []
    for p in photos:
        if p.id not in visited:
            queue = [p.id]
            while queue:
                if len(output) % 1000 == 0:
                    print(len(output))
                photo = d_photos[queue.pop()]
                should_break = False
                for tag in photo.tags:
                    if should_break:
                        break
                    for photo_id in tags[tag]:
                        if photo_id not in visited and photo_id != photo.id:
                            output.append(photo.id)
                            visited.add(photo.id)
                            queue.append(photo_id)
                            should_break = True
                            break

        return output

def group_horizontal_photos_strategy_C(photos):
    tags = {}
    d_photos = {}
    for photo in photos:
        d_photos[photo.id] = photo
        for tag in photo.tags:
            tags.setdefault(tag, [])
            tags[tag].append(photo.id)
    queue = [photos[0].id]
    visited = set()
    output = []
    while queue:
        if len(output) % 1000 == 0:
            print(len(output))
        photo = d_photos[queue.pop()]
        should_break = False
        for tag in photo.tags:
            if should_break:
                break
            for photo_id in tags[tag]:
                if photo_id not in visited and photo_id != photo.id:
                    output.append(photo.id)
                    visited.add(photo.id)
                    queue.append(photo_id)
                    should_break = True
                    break

    return output

def group_horizontal_photos_strategy_B(photos):
    photos = sorted(photos, key=lambda x: x.no_tags)
    output = [photo.id for photo in photos]
    return output

def group_horizontal_photos_strategy_A(photos):
    queue = [0]
    output = []
    while queue:
        maximum = 0
        maximum_j = None
        i = queue.pop()
        output.append(photos[i].id)
        for j in range(len(photos)):
            if i == j or photos[i] is None or photos[j] is None:
                continue
            current = photos[i].score(photos[j])
            if maximum < current:
                maximum = current
                maximum_j = j
        photos[i] = None
        if maximum_j is not None:
            queue.append(maximum_j)
    return output

if __name__ == "__main__":
    in_file_name = sys.argv[1]
    out_file_name = "{}.out".format(in_file_name.split('.')[0])
    photos = read_from_file(in_file_name)
    output = group_horizontal_photos_strategy_D(photos)
    try:
        with open('random.txt', "w+") as f:
            f.write(json.dumps(output))
    except:
        print("errored")
    write_to_output(out_file_name, len(output), [[i] for i in output])
