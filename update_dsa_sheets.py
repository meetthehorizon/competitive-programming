import os
import pandas as pd

index = 420

for comp in os.listdir(r"DSA/"):
    for file in os.listdir(os.path.join("DSA/", comp)):
        file = os.path.join("DSA/", comp, file)
        if file.endswith(".csv"):
            df = pd.read_csv(file)

            if index in df.ID:
                print(f"updating {file}...")

                df.loc[df.ID == index, "Status"] = "Done"

                df.to_csv(file, index=False)
