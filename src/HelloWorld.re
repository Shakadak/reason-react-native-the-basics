open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
        "helloWorld": style(~flex=1., ~justifyContent=`center, ~alignItems=`center, ()),
    })
  );

[@react.component]
let make = () => {
  <View style=styles##helloWorld>
    <Text>"Hello, world!"->React.string</Text>
  </View>
};
