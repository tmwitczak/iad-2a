import zipfile


# //////////////////////////////////////////////////////////////////////////// #
def extract_zip_archive(filename, destination):
    with zipfile.ZipFile(filename) as zip_archive:
        zip_archive.extractall(destination)


# //////////////////////////////////////////////////////////////////////////// #
extract_zip_archive('data.zip', '.')

# //////////////////////////////////////////////////////////////////////////// #
