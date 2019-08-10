open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
        "helloWorld": style(~flex=1., ~justifyContent=`center, ~alignItems=`center, ()),
    })
  );

[@react.component]
let app = () => {
    let uri = "https://upload.wikimedia.org/wikipedia/commons/d/de/Bananavarieties.jpg"
    let source = Image.Source.fromUriSource(Image.uriSource(~uri, ~width=193., ~height=110., ()));
    <Image source/>
};
